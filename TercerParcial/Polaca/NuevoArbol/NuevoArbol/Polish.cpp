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

void Polish::resolverEcuacion(string expPos[], int lon)
{
	for (int i = 0; i < lon; i++)
	{
		cout << expPos[i] << endl;
	}

	PilaString pil2;
	string dato;
	for (int i = 0; i < lon; i++)
	{
		dato = expPos[i];
		cout << "daato " << dato << endl;
		if (isdigit(dato.at(0))) {
			pil2.push(dato);
		}
		else {
			string op2, op1, res;
			op2 = pil2.pop();
			op1 = pil2.pop();
			res = doOperation(op1, op2, dato);
			pil2.push(res);
		}
		dato = " ";
	}
	respuesta = pil2.pop();
	//cout << "Respuesta " << pil2.pop() << endl;
}

void Polish::separar(string out)
{
	int cont = 0;
	string dato;
	for (int i = 0; i < out.length(); i++)
	{
		if (out.at(i) == ' ')
			cont += 1;
	}
	int longitud = out.length() - cont; //longitud sin espacios
	string* arr = new string[longitud];
	cont = 0;
	for (int i = 0; i < out.length(); i++)
	{
		if (out.at(i) != ' ') {
			dato += out.at(i);
		}
		else {
			arr[cont] = dato;
			cont += 1;
			dato = "";
		}
	}
	resolverEcuacion(arr, longitud);
}

string Polish::doOperation(string op1, string op2, string o)
{
	char op = o.at(0);
	switch (op)
	{
	case '+':
		if (true) {
			int res = atoi(op1.c_str()) + atoi(op2.c_str());
			return to_string(res);
		}
		break;
	case '-':
		if (true) {
			int res = atoi(op1.c_str()) - atoi(op2.c_str());
			return to_string(res);
		}
		break;
	case '*':
		if (true) {
			int res = atoi(op1.c_str()) * atoi(op2.c_str());
			return to_string(res);
		}
		break;
	case '/':
		if (true) {
			int res = atoi(op1.c_str()) / atoi(op2.c_str());
			return to_string(res);
		}
		break;
	case '^':
		if (true) {
			int res = pow(atoi(op1.c_str()), atoi(op2.c_str()));
			return to_string(res);
		}
		break;
	default:
		cout << "Esa operacion no existe" << endl;
		break;
	}
}

string Polish::stringPost(string inf[],int cont )
{
	string output;
	for (int i = 0; i < cont ; i++)
	{
		char opc = inf[i].at(0);
		if (isdigit(opc)) {
			output +=inf[i];
			output += " ";
		}
		else if (opc == '(') {
			pil1.push(opc);
		}
		else if (opc == ')') {
			while (!pil1.isEmpty()&& (char)pil1.getFirst()!='(') {
				output+=pil1.pop();
				output += " ";
			}
			if (pil1.getFirst() == '(') {
				pil1.pop();
			}
		}
		else if (!isdigit(opc)) {
			while (!pil1.isEmpty() && jerarquia(opc,(char)pil1.getFirst())){
				output += (char)pil1.pop();
				output += " ";
			}
			pil1.push(opc);
		}
	}
	while (!pil1.isEmpty()) {
		output += (char)pil1.pop();
		output += " ";
	}
	_tree._add(output);
	_tree.showTree(_tree.get_root(),1);
<<<<<<< Updated upstream
	_tree.
	separar(output);
=======
	cout << "Inorden" << endl;
	_tree.imprimirInorden(_tree.get_root());
	cout<<endl << "Preorden" << endl;
	_tree.imprimirPreorden(_tree.get_root());
	cout<<endl<< "Postorden" << endl;
>>>>>>> Stashed changes
	return output;
}
