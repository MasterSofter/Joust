#include "AI.IdleRightState.h"
#include "AI.StateMachine.h"
namespace AI
{
	IdleRightState::IdleRightState(Enemy* enemy)
		: State(enemy, STATE_NAME_IDLE_RIGHT)
	{

	}

	IdleRightState::~IdleRightState()
	{

	}

	void IdleRightState::Do(float deltaTime)
	{
		if (_enemyPtr != nullptr && !_enemyPtr->animation.Working)
		{
			_enemyPtr->setVelocity(sf::Vector2f(0, _enemyPtr->getVelocity().y));
			_enemyPtr->gameObject.setScale(sf::Vector2f(1 / 7.f, 1));
			_enemyPtr->animation.setCurrentImagePos(sf::Vector2u(2, 1));
			_enemyPtr->animation.setImageCountDrawable(sf::Vector2u(1, 1));
			_enemyPtr->animation.setSwitchTime(0.4f);
			_enemyPtr->animation.Working = true;
		}

		if (this->_enemyPtr != nullptr)
		{
			//���� ������ ���� ���������
			//����� �������� ����� ���� � player �� x
			float directX = _enemyPtr->playergetPosition().x - _enemyPtr->getPosition().x;

			if (directX > 0)
			{
				//������ ��������� ������ �� ���������� ��������� �� ���������� ������

				//���� ������� � ��������� ������ ������
				this->_enemyPtr->stateMachine->moveToState(STATE_NAME_GORIGHT);
			}
			else
			{
				//������ ��������� ����� �� ���������� ��������� �� ���������� ������

				//���� ������� � ��������� ������ �����
			}
		}

		_enemyPtr->animation.Update(sf::Vector2u(2, 1), deltaTime);
		_enemyPtr->gameObject.setTextureRect(_enemyPtr->animation.uvRect);
	}
}