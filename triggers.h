#pragma once
#include <string>
#include <vector>
#include "main.h"
#include "actions.h"
#include "vehicles.h"

using std::string;
using std::vector;

class trigger {
protected:
	bool oneShot;
	bool sequentialActions;
	int priority = 0;
	int fireDelFrames = 0;
	double fireDelay;
	double debounce;
	double activationDelay;
	double creationRadius;
	double lifetime;
	string name;
	string longComment;
	string shortComment;
	position drawPosition;
	position position;
	vector <actions> Actions;

public:
	trigger() : sequentialActions (false), oneShot(false), fireDelay(0), debounce(0), activationDelay(0), creationRadius (0), lifetime (0) {
	}

	trigger(bool seq, bool shot, double delay, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long, 
		string Short, position Draw, position Pos, vector <actions> Act) : sequentailActions (seq), oneShot(shot), fireDelay(delay),
			debounce(Debounce), activationDelay (actDelay), creationRadius (creRad), lifetime (LifeTime), name (Name), longComment (Long),
				shortComment(Short), drawPosition (Draw), position (Pos), Actions (Act){

	}

	void addAction(actions newAction) {
		Actions.push_back(newAction);
		return;
	}
};

class expressionTrigger : public trigger {
private:
	string expression;
public:
	expressionTrigger() : trigger() {
	}

	expressionTrigger(bool seq, bool shot, double delay, double Debounce, double actDelay, double creRad, double LifeTime, string Name, string Long,
		string Short, position Draw, position Pos, vector <actions> Act, string Expression) : trigger(shot, delay, Debounce, actDelay, creRad, 
			LifeTime, Name, Long, Short, Draw, Pos, vector <actions> Act) {
		expression = Expression;
	}
};