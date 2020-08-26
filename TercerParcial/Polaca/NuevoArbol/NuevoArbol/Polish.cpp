#include "Polish.h"

bool Polish::jerarquia(char op1,char op2)
{
	int cont = 0, cont1 = 0;
	char operadores[] = {'^','/','*','+','-' };
	if (op2 != '(') {
		for (int i = 0; i<5; i++)
		{
			if (operadores[i] == op2) {
				cont = i;
			}
			if (operadores[i] == op1) {
				cont1 = i;
			}
		}	
		return cont <= cont1;
	}else	return false;
}

string Polish::stringPost(string inf[],int cont )
{
	
	string output;
	for (int i = 0; i < cont ; i++)
	{
		char opc = inf[i].at(0);
		if (isdigit(opc)) {
			output += inf[i];
		}
		else if (opc == '(') {
			pil1.push(opc);
		}
		else if (opc == ')') {
			while (!pil1.isEmpty()&& (char)pil1.getFirst()!='(') {
				output+=pil1.pop();	
			}
			if (pil1.getFirst() == '(') {
				pil1.pop();
			}
		}
		else if (!isdigit(opc)) {
			while (!pil1.isEmpty() && jerarquia(opc,(char)pil1.getFirst())){
				output += (char)pil1.pop();
			}
			pil1.push(opc);
		}
	}
	while (!pil1.isEmpty()) {
		output += (char)pil1.pop();
	}


	return output;
}
