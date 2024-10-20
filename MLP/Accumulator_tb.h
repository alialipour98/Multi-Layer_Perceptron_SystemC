#include "Accumulator.h"

SC_MODULE(Accumulator_tb)
{
	sc_signal <sc_logic>  Clock;
	sc_signal <sc_logic>  Reset;
	sc_signal <sc_logic>   Load;
	sc_signal <sc_logic>   INIT;

	sc_signal <sc_lv<8>>  INPUT;
	sc_signal <sc_lv<8>>  Bias_In;
	sc_signal <sc_lv<8>> OUTPUT;

	AccRegister<8>* Acc;

	SC_CTOR(Accumulator_tb)
	{
		Acc = new AccRegister<8>("Counter_8Bit");
		Acc->Clock(Clock);
		Acc->Reset(Reset);
		Acc->Load(Load);
		Acc->INIT(INIT);
		Acc->INPUT(INPUT);
		Acc->Bias_In(Bias_In);
		Acc->OUTPUT(OUTPUT);

		SC_THREAD(clocking);
		SC_THREAD(inputing);
	}

	void clocking();
	void inputing();
};

void Accumulator_tb::clocking()
{
	while (true)
	{
		wait(10, SC_NS);
		Clock = SC_LOGIC_0;
		wait(10, SC_NS);
		Clock = SC_LOGIC_1;
	}
}
void Accumulator_tb::inputing()
{
	INIT = SC_LOGIC_0;
	Load = SC_LOGIC_0;

	Bias_In = sc_lv<8>(12);

	Reset = SC_LOGIC_1;
	wait(10, SC_NS);
	Reset = SC_LOGIC_0;
	wait(10, SC_NS);

	INIT = SC_LOGIC_1;
	wait(10, SC_NS);
	INIT = SC_LOGIC_0;
	wait(50, SC_NS);

	INPUT = "00100100";
	wait(37, SC_NS);

	Load = SC_LOGIC_1;
	wait(10, SC_NS);
	Load = SC_LOGIC_0;

	INPUT = "11100100";
	wait(29, SC_NS);
	INPUT = "11100100";
	wait(31, SC_NS);

	Load = SC_LOGIC_1;
	wait(20, SC_NS);
	Load = SC_LOGIC_0;

	INPUT = "11100100";
	wait(13, SC_NS);
	INPUT = "11100100";
	wait(17, SC_NS);
}
