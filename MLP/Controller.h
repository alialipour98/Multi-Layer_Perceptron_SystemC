#include <systemc.h>

SC_MODULE(Controller) {

	sc_in  <sc_logic>     Done;
	sc_in  <sc_logic>    Clock;
	sc_in  <sc_logic>    Reset;
	sc_in  <sc_logic>    Start;
	sc_out <sc_logic>      INC;
	sc_out <sc_logic>    Load1;
	sc_out <sc_logic>    Load2;
	sc_out <sc_logic>    INIT1;
	sc_out <sc_logic>    INIT2;
	sc_out <sc_logic>   ReadRF;
	sc_out <sc_logic>   INIT_C;
	sc_out <sc_logic>   LoadRF;
	sc_out <sc_logic>  LoadACC;
	sc_out <sc_logic> INIT_ACC;

	enum states {
		INIT , STRT , LD_RF,
		LD_PR, LD_AC, NOP
	};

	sc_signal <states> Present_State, Next_State;

	SC_CTOR(Controller)
	{
		SC_METHOD(comb_S_function);
		sensitive << Present_State << Start << Done;
		SC_METHOD(comb_O_function);
		sensitive << Present_State;
		SC_THREAD(seq_function);
		sensitive << Clock << Reset;
	};

	void comb_S_function();
	void comb_O_function();
	void seq_function();
};

void Controller::comb_O_function()
{
	// Inactive output values
	ReadRF   = SC_LOGIC_0;
	INC      = SC_LOGIC_0;
	Load1    = SC_LOGIC_0;
	Load2    = SC_LOGIC_0;
	LoadRF   = SC_LOGIC_0;
	LoadACC  = SC_LOGIC_0;
	INIT1    = SC_LOGIC_0;
	INIT2    = SC_LOGIC_0;
	INIT_C   = SC_LOGIC_0;
	INIT_ACC = SC_LOGIC_0;

	switch (Present_State) {
	case INIT:
		INIT1    = SC_LOGIC_1;
		INIT2    = SC_LOGIC_1;
		INIT_C   = SC_LOGIC_1;
		break;
	case LD_RF:
		LoadRF   = SC_LOGIC_1;
		INIT_ACC = SC_LOGIC_1;
		break;
	case LD_PR:
		Load1    = SC_LOGIC_1;
		Load2    = SC_LOGIC_1;
		ReadRF   = SC_LOGIC_1;
		break;
	case LD_AC:
		LoadACC  = SC_LOGIC_1;
		INC      = SC_LOGIC_1;
		break;
	default:
		ReadRF   = SC_LOGIC_0;
		INC      = SC_LOGIC_0;
		Load1    = SC_LOGIC_0;
		Load2    = SC_LOGIC_0;
		LoadRF   = SC_LOGIC_0;
		LoadACC  = SC_LOGIC_0;
		INIT1    = SC_LOGIC_0;
		INIT2    = SC_LOGIC_0;
		INIT_C   = SC_LOGIC_0;
		INIT_ACC = SC_LOGIC_0;
	}
}
void Controller::comb_S_function() {
	switch (Present_State) {
	case INIT:
		if (Start.read() == '1')
			Next_State = STRT;
		else
			Next_State = INIT;
		break;
	case STRT:
		if (Start.read() == '0')
			Next_State = LD_RF;
		else
			Next_State = STRT;
		break;
	case LD_RF:
		Next_State = LD_PR;
		break;
	case LD_PR:
		Next_State = LD_AC;
		break;
	case LD_AC:
			Next_State = NOP;
		break;
	case NOP:
		if (Done.read() == '1')
			Next_State = INIT;
		else
			Next_State = LD_PR;
		break;
	default:
		Next_State = INIT;
	}
}
void Controller::seq_function() {
	while (1) {
		if (Reset == '1')
			Present_State = INIT;
		else if (Clock->event() && (Clock == '1'))
			Present_State = Next_State;
		wait();
	}
}
