#include "Register_src.h"

SC_MODULE(Register_src_tb)
{
	sc_signal <sc_logic>  Clock;
	sc_signal <sc_logic>  Reset;
	sc_signal <sc_logic>   Load;
	sc_signal <sc_logic>   INIT;

	sc_signal <sc_lv<8>>  INPUT;
	sc_signal <sc_lv<8>> OUTPUT;

	dRegister<8>* Reg;

	SC_CTOR(Register_src_tb)
	{
		Reg = new dRegister<8>("Counter_8Bit");
		Reg->Clock(Clock)  ;
		Reg->Reset(Reset)  ;
		Reg->Load(Load)    ;
		Reg->INIT(INIT)    ;
		Reg->INPUT(INPUT)  ;
		Reg->OUTPUT(OUTPUT);

		SC_THREAD(clocking);
		SC_THREAD(inputing);
	}

	void clocking();
	void inputing();
};

void Register_src_tb::clocking()
{
	while (true)
	{
		wait(10, SC_NS);
		Clock = SC_LOGIC_0;
		wait(10, SC_NS);
		Clock = SC_LOGIC_1;
	}
}
void Register_src_tb::inputing()
{
	INIT  = SC_LOGIC_0;
	Load  = SC_LOGIC_0;

	Reset = SC_LOGIC_1;
	wait(10, SC_NS);
	Reset = SC_LOGIC_0;
	wait(10, SC_NS);

	INPUT = "00100100";
	wait(37, SC_NS);

	Load  = SC_LOGIC_1;
	wait(10, SC_NS);
	Load  = SC_LOGIC_0;

	INPUT = "11100100";
	wait(29, SC_NS);
	INPUT = "11100100";
	wait(31, SC_NS);

	Load  = SC_LOGIC_1;
	wait(20, SC_NS);
	Load  = SC_LOGIC_0;

	INPUT = "11100100";
	wait(13, SC_NS);
	INPUT = "11100100";
	wait(17, SC_NS);
}
