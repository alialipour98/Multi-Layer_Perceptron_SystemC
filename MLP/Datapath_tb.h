#include "Datapath.h"

SC_MODULE(Datapath_tb)
{
	sc_signal <sc_logic> Clock;
	sc_signal <sc_logic> Reset;
	sc_signal <sc_logic> ReadRF;
	sc_signal <sc_logic> INC;
	sc_signal <sc_logic> Load1;
	sc_signal <sc_logic> Load2;
	sc_signal <sc_logic> LoadRF;
	sc_signal <sc_logic> LoadACC;
	sc_signal <sc_logic> INIT1;
	sc_signal <sc_logic> INIT2;
	sc_signal <sc_logic> INIT_C;
	sc_signal <sc_logic> INIT_ACC;
	sc_signal <sc_logic> Done;
	sc_signal <sc_lv<8>> INPUT_0;
	sc_signal <sc_lv<8>> INPUT_1;
	sc_signal <sc_lv<8>> INPUT_2;
	sc_signal <sc_lv<8>> INPUT_3;
	sc_signal <sc_lv<8>> INPUT_4;
	sc_signal <sc_lv<8>> INPUT_5;
	sc_signal <sc_lv<8>> INPUT_6;
	sc_signal <sc_lv<8>> INPUT_7;
	sc_signal <sc_lv<8>> INPUT_8;
	sc_signal <sc_lv<8>> INPUT_9;
	sc_signal <sc_lv<8>> Weight_0;
	sc_signal <sc_lv<8>> Weight_1;
	sc_signal <sc_lv<8>> Weight_2;
	sc_signal <sc_lv<8>> Weight_3;
	sc_signal <sc_lv<8>> Weight_4;
	sc_signal <sc_lv<8>> Weight_5;
	sc_signal <sc_lv<8>> Weight_6;
	sc_signal <sc_lv<8>> Weight_7;
	sc_signal <sc_lv<8>> Weight_8;
	sc_signal <sc_lv<8>> Weight_9;
	sc_signal <sc_lv<8>> Bias;
	sc_signal <sc_lv<8>> OUTPUT_I;
	sc_signal <sc_lv<8>> OUTPUT_II;

	Datapath<4, 10>* DP;

	SC_CTOR(Datapath_tb)
	{
		DP = new Datapath<4, 10>("Datapath");
		DP->Clock(Clock);
		DP->Reset(Reset);
		DP->ReadRF(ReadRF);
		DP->INC(INC);
		DP->Load1(Load1);
		DP->Load2(Load2);
		DP->LoadRF(LoadRF);
		DP->LoadACC(LoadACC);
		DP->INIT1(INIT1);
		DP->INIT2(INIT2);
		DP->INIT_C(INIT_C);
		DP->INIT_ACC(INIT_ACC);
		DP->Done(Done);
		DP->INPUT_0(INPUT_0);
		DP->INPUT_1(INPUT_1);
		DP->INPUT_2(INPUT_2);
		DP->INPUT_3(INPUT_3);
		DP->INPUT_4(INPUT_4);
		DP->INPUT_5(INPUT_5);
		DP->INPUT_6(INPUT_6);
		DP->INPUT_7(INPUT_7);
		DP->INPUT_8(INPUT_8);
		DP->INPUT_9(INPUT_9);
		DP->Weight_0(Weight_0);
		DP->Weight_1(Weight_1);
		DP->Weight_2(Weight_2);
		DP->Weight_3(Weight_3);
		DP->Weight_4(Weight_4);
		DP->Weight_5(Weight_5);
		DP->Weight_6(Weight_6);
		DP->Weight_7(Weight_7);
		DP->Weight_8(Weight_8);
		DP->Weight_9(Weight_9);
		DP->Bias(Bias);
		DP->OUTPUT_I(OUTPUT_I);
		DP->OUTPUT_II(OUTPUT_II);

		SC_THREAD(clocking);
		SC_THREAD(inputing);
	}

	void clocking();
	void inputing();
};

void Datapath_tb::clocking()
{
	while (true)
	{
		wait(10, SC_NS);
		Clock = SC_LOGIC_0;
		wait(10, SC_NS);
		Clock = SC_LOGIC_1;
	}
}
void Datapath_tb::inputing()
{
	INPUT_0 = sc_lv<8>(12);
	INPUT_1 = sc_lv<8>(34);
	INPUT_2 = sc_lv<8>(21);
	INPUT_3 = sc_lv<8>(10);
	INPUT_4 = sc_lv<8>(0);
	INPUT_5 = sc_lv<8>(0);
	INPUT_6 = sc_lv<8>(0);
	INPUT_7 = sc_lv<8>(0);
	INPUT_8 = sc_lv<8>(0);
	INPUT_9 = sc_lv<8>(0);

	Weight_0 = sc_lv<8>(+13);
	Weight_1 = sc_lv<8>(-46);
	Weight_2 = sc_lv<8>(-42);
	Weight_3 = sc_lv<8>(+16);
	Weight_4 = sc_lv<8>(0);
	Weight_5 = sc_lv<8>(0);
	Weight_6 = sc_lv<8>(0);
	Weight_7 = sc_lv<8>(0);
	Weight_8 = sc_lv<8>(0);
	Weight_9 = sc_lv<8>(0);

	Bias = sc_lv<8>(+10);

	LoadRF = SC_LOGIC_1;
	wait(10, SC_NS);
	LoadRF = SC_LOGIC_0;

	INIT_ACC = SC_LOGIC_1;
	Load1 = SC_LOGIC_1;
	Load2 = SC_LOGIC_1;
	ReadRF = SC_LOGIC_1;
	wait(10, SC_NS);
	Load1 = SC_LOGIC_0;
	Load2 = SC_LOGIC_0;
	ReadRF = SC_LOGIC_0;
	INIT_ACC = SC_LOGIC_0;
	wait(10, SC_NS);
	LoadACC = SC_LOGIC_1;
	wait(10, SC_NS);
	LoadACC = SC_LOGIC_0;
	INC = SC_LOGIC_1;
	wait(10, SC_NS);
	INC = SC_LOGIC_0;



}
