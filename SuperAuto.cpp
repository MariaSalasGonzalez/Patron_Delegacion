#include <iostream>
using namespace std;

class medioTransporte { //clase abstracta
public:
	virtual void encender() = 0; //MVP
	virtual void andar() = 0; //MVP
};

class helicoptero : public medioTransporte {
public:
	void encenderMotor() {
		cout << "Helicoptero-encendiendo motor" << endl;
	}

	void andar() {
		cout << "Helicoptero-andando" << endl;
	}

	void descender() {
		cout << "Helicoptero-descendiendo" << endl;
	}

	void ascender() {
		cout << "Helicoptero-ascendiendo" << endl;
	}
};

class autoMovil : public medioTransporte {
public:
		void encenderMotor() {
			cout << "Automovil-encendiendo motor" << endl;
		}

		void andar() {
			cout << "Automovil-andando" << endl;
		}
};

class barco : public medioTransporte {
public:
		void encenderMotor() {
			cout << "Barco-encendiendo motor" << endl;
		}

		void andar(){
			cout << "Barco-andando" << endl;
		}
};

class submarino : public barco {
public:
		void ascender() {
			cout << "Submarino-ascendiendo " << endl;
		}

		void descender() {
			cout << "Submarino-descendiendo" << endl;
		}
};

class superAuto : public autoMovil{
private:
	   //esto es una composicion
		submarino* subPtr; //flecha hacia submarino
		helicoptero* helPtr; //flecha hacia helicoptero
public:
	superAuto() {
		cout << "Creando Super Auto Movil" << endl;
		subPtr = new submarino(); //chip
		helPtr = new helicoptero(); //chip
	}

	virtual ~superAuto() {
		cout << "Eliminando super auto movil" << endl;
		delete subPtr;
		delete helPtr;
	}

	void rodar() {
		encenderMotor();
		andar();
	}

	void navegar() {
		subPtr->encenderMotor();
		subPtr->andar();
	}

	void navegarAscendiendo() {
		subPtr->ascender();
	}

	void navegarDescendiendo() {
		subPtr->descender();
	}

	void volar() {
		helPtr->encenderMotor();
		helPtr->andar();
	}

	void volarAscendiendo() {
		helPtr->ascender();
	}

	void volarDescendiendo() {
		helPtr->descender();
	}
};


int main() {
	cout << "-----EJERCICIO CON SUPER AUTO MOVIL------" << endl;
	cout << "-----------------------------------------" << endl;
	superAuto* autoFantastico = new superAuto();
	cout << endl;
	cout << "Funcionamiento con AutoMovil" << endl;
	autoFantastico->rodar();
	cout << endl;
	cout << "Funcionamiento como sumergible" << endl;
	autoFantastico->navegar();
	autoFantastico->navegarDescendiendo();
	autoFantastico->navegarAscendiendo();
	cout << endl;
	cout << "Funcionamiento como helicoptero" << endl;
	autoFantastico->volar();
	autoFantastico->volarDescendiendo();
	autoFantastico->volarAscendiendo();
	cout << endl;
	cout << "-----------------------------------------" << endl;
	cout << endl << endl;
	delete autoFantastico;
	system("pause");
	return 0;
}