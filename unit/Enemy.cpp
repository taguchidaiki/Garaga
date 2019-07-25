#include "Enemy.h"
#include <stdlib.h>

Enemy::Enemy()
{
	
}

Enemy::Enemy(Vector2D pos, float speed, std::string imageName, std::string fileName, Vector2 divSize, Vector2 divCnt, int id)
{
	TRACE("�G�l�~�[����\n");
	_state.pos = pos;
	_state.speed = speed;
	Obj::Init(imageName, fileName, divSize, divCnt, id);
	Init();
}

Enemy::Enemy(STATUS state, std::pair<Vector2D, float> eArea)
{
	TRACE("�G�l�~�[����\n");
	_goalArea = eArea;
	Obj::Init(state);
	Init();
}


Enemy::~Enemy()
{
	TRACE("�G�l�~�[�폜\n");
}

void Enemy::Draw(void)
{
	DrawRotaGraph(_state.pos.x + _state.divSize.x / 2, _state.pos.y + _state.divSize.y / 2,
		1.0, PI / 2,
		IMAGE_ID(_state.imageName)[_state.id], true);
}

void Enemy::Update(void)
{
	if (DestroyProc())
	{
		return; 
	}

	(this->*_actTbl[static_cast<int>(_actMode)])();
	
	/*if (rand() % 1200 == 0)
	{
		_alive = false;
		animKey(ANIM::BLAST);
	}*/
	
}

UNIT_ID Enemy::GetUnitType(void)
{
	return UNIT_ID::ENEMY;
}

int Enemy::Idle(void)
{
	return 0;
}

int Enemy::Move(void)
{
	//�����ړ��̎���
	//�S�[���n�_���猻�ݒn�_�܂ł̕����𐳋K�����Ă�����
	//pos�ɃX�s�[�h*���������Z����΂��̕����Ɍ�����
	/*_state.mov = Normalize(Vector2D(_goalArea.first - _state.pos));

	_state.pos += _state.mov * _state.speed;

	if (sqrt(pow(_state.pos.x - _goalArea.first.x,2) + pow(_state.pos.y - _goalArea.first.y,2)) <= _goalArea.second)
	{
		_state.pos = _goalArea.first;
		_actMode = ENE_ACT::IDLE;
	}*/

	//Sigmoid({ 0.0f,0.0f }, _goalArea.first, 4.5f);

	Cyclone();
	
	return 0;
}

float Enemy::Sigmoid(float x, float a)
{
	float f1 = ((1 - exp(-a * (2 * x - 1))) / (1 + exp(-a * (2 * x - 1))));
	float f2 = ((1 + exp(-a)) / (1 - exp(-a)));

	return (1.0f / 2.0f) * (1 + (f1 * f2));
}

bool Enemy::Sigmoid(Vector2D start, Vector2D end, float til)
{
	/*f(x) = 1�@/ (1 + exp(-ax));	�V�O���C�h�Ȑ�(a > 0)*/
	/*�X�����`���Đ��K�����ꂽ�ړ��ʂ����Ă����邩�ocos��sin�Ɓp�����邩tan�Ƃ̒l�𕪉����邩*/
	Vector2D _til = { 0.1f / 3, (Sigmoid(count + 0.1f / 3, til) - Sigmoid(count, til))};
	count += (0.1f / 3);
	//_til.Normalized();
	_state.pos.x += _til.x * (end.x - start.x);
	_state.pos.y += _til.y * (end.y - start.y);

	if (count >= 1.0f)
	{
		_actMode = ENE_ACT::IDLE;
	}
	
	return true;
}

bool Enemy::Cyclone(void)
{
	//���S{100,100},���a100�̉E���̓�����������
	//�Ƃ̒l�͓G�̈ʒu�ƖړI�̉~�̒��S�n�̃x�N�g�����g���Ώo����͂�
	Vector2D vec = {_state.pos.x - 100, _state.pos.y - 100};
	double theta = atan2(vec.x,vec.y);
	//theta -= (2 * PI / 360);
	_state.pos.x = 100 * cos(theta);
	_state.pos.y = 100 * sin(theta);
	
	return false;
}

bool Enemy::Cyclone(Vector2D start, Vector2D end)
{
	return false;
}

bool Enemy::Init(void)
{
	AnimVector data;
	data.reserve(2);
	//data.push_back(std::make_pair(IMAGE_ID("�L����")[0], 30));
	//data.emplace_back(std::make_pair(IMAGE_ID("�L����")[0], 30));
	data.emplace_back(IMAGE_ID("kyara")[_state.id], 30);
	data.emplace_back(IMAGE_ID("kyara")[_state.id + 1], 60);
	SetAnim(ANIM::NORMAL, data);
	//data.clear();
	
	data.reserve(6);
	for (int i = 0; i < 5; ++i)
	{
		data.emplace_back(IMAGE_ID("enblast")[i], 30 * (i + 1));
	}
	data.emplace_back(-1, 180);
	SetAnim(ANIM::BLAST, data);

	_actTbl[static_cast<int>(ENE_ACT::IDLE)] = &Enemy::Idle;
	_actTbl[static_cast<int>(ENE_ACT::MOVE)] = &Enemy::Move;

	_actMode = ENE_ACT::MOVE;
	return true;
}
