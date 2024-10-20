#include "Multiplier.h"

SC_MODULE(Multiplier_tb)
{
	sc_signal <sc_lv<8>>  INPUT_1;
	sc_signal <sc_lv<8>>  INPUT_2;
	sc_signal <sc_lv<16>>  OUTPUT;

	Mult<8, 16>* Multiply;

	SC_CTOR(Multiplier_tb)
	{
		Multiply = new Mult<8, 16>("Multiplier");

		Multiply->INPUT_1(INPUT_1);
		Multiply->INPUT_2(INPUT_2);
		Multiply->OUTPUT(OUTPUT)  ;

		SC_THREAD(inputing);
	}

	void inputing();
};

void Multiplier_tb::inputing()
{
	INPUT_1 = sc_lv<8>(12);
	INPUT_2 = sc_lv<8>(-12);
	wait(10, SC_NS);
	INPUT_1 = sc_lv<8>(-15);
	INPUT_2 = sc_lv<8>(-12);
	wait(10, SC_NS);
	INPUT_1 = sc_lv<8>(-23);
	INPUT_2 = sc_lv<8>(-2);
	wait(10, SC_NS);
	INPUT_1 = sc_lv<8>(12);
	INPUT_2 = sc_lv<8>(12);
	wait(10, SC_NS);

}
