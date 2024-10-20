#include "N_Bit_Counter.h"

SC_MODULE(N_Bit_Counter_tb)
{
	sc_signal <sc_logic>  Clock;
	sc_signal <sc_logic>  Reset;
	sc_signal <sc_logic>  INIT ;
	sc_signal <sc_logic>  INC  ;
	sc_signal <sc_lv<8>> OUTPUT;

	nBitCounter<8>* cnt;
	
	SC_CTOR(N_Bit_Counter_tb)
	{
		cnt = new nBitCounter<8> ("Counter_8Bit");
		cnt->Clock(Clock);
		cnt->Reset(Reset);
		cnt->INIT(INIT);
		cnt->INC(INC);
		cnt->OUTPUT(OUTPUT);

		SC_THREAD(clocking);
		SC_THREAD(inputing);
	}

	void clocking();
	void inputing();
};

void N_Bit_Counter_tb::clocking()
{
	while (true)
	{
		wait(10, SC_NS);
		Clock = SC_LOGIC_0;
		wait(10, SC_NS);
		Clock = SC_LOGIC_1;
	}
}
void N_Bit_Counter_tb::inputing()
{

	INIT  = SC_LOGIC_0;
	INC	  = SC_LOGIC_0;

	Reset = SC_LOGIC_1;
	wait(10, SC_NS);
	Reset = SC_LOGIC_0;
	wait(10, SC_NS);
	INC   = SC_LOGIC_1;
	wait(10, SC_NS);
	INC   = SC_LOGIC_0;
	wait(10, SC_NS);
	INC   = SC_LOGIC_0;
	wait(10, SC_NS);
	INC   = SC_LOGIC_0;
	wait(10, SC_NS);
	INC   = SC_LOGIC_0;
	wait(10, SC_NS);
	INC   = SC_LOGIC_1;
	wait(10, SC_NS);
	INIT = SC_LOGIC_1;
	wait(10, SC_NS);
	INIT = SC_LOGIC_0;
}
