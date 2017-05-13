#pragma once
#include<iostream>
#include <string>
#include "ruleobj.h"
#include "symObj.h"
using namespace std;

//TreeNode* create_Kid(symObj child, int NodeID, ruleobj rule);
class TreeNode
{
public:
	TreeNode() {
		setID(0);
		setSymKind(0);
		setSymID(0);

	}


	TreeNode(int id, int sym_id, int isTerm, int rule) {
		setID(id);
		setSymKind(sym_id);
		setSymID(isTerm);
	};

private:
	int ID;
	int symID;
	//token?
	int symKind; // 0 for nonterminal, 1 for terminal
	TreeNode* kids[10];
	int ruleID;
public:
	//void setKid(int slot, symObj child, int NodeID, ruleobj rule) { kids[slot] = create_Kid(child, NodeID, rule); }
	void setKid(TreeNode* kid, int slotNumber) {
		kids[slotNumber] = kid;
	}
	void setID(int id) { ID = id; }
	void setSymKind(int kind) { symKind = kind; }
	void setSymID(int symid) { symID = symid; }
	void setRuleID(int ruleid) { ruleID = ruleid; }

};

//TreeNode* create_Kid(symObj child, int NodeID, ruleobj rule) { return new TreeNode(NodeID, child.getSymid(), child.getSymkind(), rule.getID()); }