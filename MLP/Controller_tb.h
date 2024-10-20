#include "Controller.h"

SC_MODULE(Controller_tb)
{
	sc_signal<sc_logic>    Clock;
	sc_signal<sc_logic>    Reset;
	sc_signal<sc_logic>    Start;
	sc_signal<sc_logic>     Done;

	sc_signal<sc_logic>     ReadRF;
	sc_signal<sc_logic>     INC;
	sc_signal<sc_logic>     Load1;
	sc_signal<sc_logic>     Load2;
	sc_signal<sc_logic>     LoadRF;
	sc_signal<sc_logic>     LoadACC;
	sc_signal<sc_logic>     INIT1;
	sc_signal<sc_logic>     INIT2;
	sc_signal<sc_logic>     INIT_C;
	sc_signal<sc_logic>     INIT_ACC;

	enum states {
		INIT, STRT, LD_RF,
		LD_PR, LD_AC, NOP
	};

	Controller* ctrl;

	SC_CTOR(Controller_tb)
	{
		ctrl = new Controller("Controller");
		ctrl->Clock(Clock);
		ctrl->Reset(Reset);
		ctrl->Start(Start);
		ctrl->Done(Done);
		ctrl->ReadRF(ReadRF);
		ctrl->INC(INC);
		ctrl->Load1(Load1);
		ctrl->Load2(Load2);
		ctrl->LoadRF(LoadRF);
		ctrl->LoadACC(LoadACC);
		ctrl->INIT1(INIT1);
		ctrl->INIT2(INIT2);
		ctrl->INIT_C(INIT_C);
		ctrl->INIT_ACC(INIT_ACC);

		SC_THREAD(clocking);
		SC_THREAD(inputing);
	}

	void clocking();
	void inputing();
};

void Controller_tb::clocking()
{
	while (true)
	{
		wait(5, SC_NS);
		Clock = SC_LOGIC_0;
		wait(5, SC_NS);
		Clock = SC_LOGIC_1;
	}
}
void Controller_tb::inputing()
{
	Done = SC_LOGIC_0;
	Start= SC_LOGIC_0;
	Reset = SC_LOGIC_0;

	wait(20, SC_NS);
	Reset = SC_LOGIC_1;
	wait(10, SC_NS);
	Reset = SC_LOGIC_0;
	wait(10, SC_NS);

	Start = SC_LOGIC_1;
	wait(10, SC_NS);
	Start = SC_LOGIC_0;

	wait(1000, SC_NS);

	Done = SC_LOGIC_1;
	wait(10, SC_NS);
	Done = SC_LOGIC_0;

}
