#include "Datapath.h"
#include "Controller.h"

template <int Counter_Width, int Comp_Value>
SC_MODULE(Single_Neuron)
{
	sc_in     <sc_logic>              Clock;
	sc_in     <sc_logic>              Reset;
	sc_in     <sc_logic>              Start;
	sc_out    <sc_logic>           Done_OUT;

	sc_in    <sc_lv<8>>  INPUT_0;
	sc_in    <sc_lv<8>>  INPUT_1;
	sc_in    <sc_lv<8>>  INPUT_2;
	sc_in    <sc_lv<8>>  INPUT_3;
	sc_in    <sc_lv<8>>  INPUT_4;
	sc_in    <sc_lv<8>>  INPUT_5;
	sc_in    <sc_lv<8>>  INPUT_6;
	sc_in    <sc_lv<8>>  INPUT_7;
	sc_in    <sc_lv<8>>  INPUT_8;
	sc_in    <sc_lv<8>>  INPUT_9;

	sc_in    <sc_lv<8>> Weight_0;
	sc_in    <sc_lv<8>> Weight_1;
	sc_in    <sc_lv<8>> Weight_2;
	sc_in    <sc_lv<8>> Weight_3;
	sc_in    <sc_lv<8>> Weight_4;
	sc_in    <sc_lv<8>> Weight_5;
	sc_in    <sc_lv<8>> Weight_6;
	sc_in    <sc_lv<8>> Weight_7;
	sc_in    <sc_lv<8>> Weight_8;
	sc_in    <sc_lv<8>> Weight_9;

	sc_in    <sc_lv<8>>     Bias;

	sc_out    <sc_lv<8>>OUTPUT_I;
	sc_out    <sc_lv<8>>OUTPUT_II;

	sc_signal <sc_logic>      INC;
	sc_signal <sc_logic>    INIT1;
	sc_signal <sc_logic>    INIT2;
	sc_signal <sc_logic>    Load1;
	sc_signal <sc_logic>    Load2;
	sc_signal <sc_logic>   ReadRF;
	sc_signal <sc_logic>   INIT_C;
	sc_signal <sc_logic>   LoadRF;
	sc_signal <sc_logic>  LoadACC;
	sc_signal <sc_logic> INIT_ACC;
	sc_signal <sc_logic> Done_Int;

	Datapath<4, Comp_Value>* DP_Neuron;
	Controller * CTRL_Neuron;

	SC_CTOR(Single_Neuron)
	{
		DP_Neuron = new Datapath<4, Comp_Value>("Dathpath");
		DP_Neuron->Clock(Clock);
		DP_Neuron->Reset(Reset);
		DP_Neuron->ReadRF(ReadRF);
		DP_Neuron->INC(INC);
		DP_Neuron->Load1(Load1);
		DP_Neuron->Load2(Load2);
		DP_Neuron->LoadRF(LoadRF);
		DP_Neuron->LoadACC(LoadACC);
		DP_Neuron->INIT1(INIT1);
		DP_Neuron->INIT2(INIT2);
		DP_Neuron->INIT_C(INIT_C);
		DP_Neuron->INIT_ACC(INIT_ACC);
		DP_Neuron->Done(Done_Int);
		DP_Neuron->INPUT_0(INPUT_0);
		DP_Neuron->INPUT_1(INPUT_1);
		DP_Neuron->INPUT_2(INPUT_2);
		DP_Neuron->INPUT_3(INPUT_3);
		DP_Neuron->INPUT_4(INPUT_4);
		DP_Neuron->INPUT_5(INPUT_5);
		DP_Neuron->INPUT_6(INPUT_6);
		DP_Neuron->INPUT_7(INPUT_7);
		DP_Neuron->INPUT_8(INPUT_8);
		DP_Neuron->INPUT_9(INPUT_9);
		DP_Neuron->Weight_0(Weight_0);
		DP_Neuron->Weight_1(Weight_1);
		DP_Neuron->Weight_2(Weight_2);
		DP_Neuron->Weight_3(Weight_3);
		DP_Neuron->Weight_4(Weight_4);
		DP_Neuron->Weight_5(Weight_5);
		DP_Neuron->Weight_6(Weight_6);
		DP_Neuron->Weight_7(Weight_7);
		DP_Neuron->Weight_8(Weight_8);
		DP_Neuron->Weight_9(Weight_9);
		DP_Neuron->Bias(Bias);
		DP_Neuron->OUTPUT_I(OUTPUT_I);
		DP_Neuron->OUTPUT_II(OUTPUT_II);

		CTRL_Neuron = new Controller("Controller");
		CTRL_Neuron->Clock(Clock);
		CTRL_Neuron->Reset(Reset);
		CTRL_Neuron->ReadRF(ReadRF);
		CTRL_Neuron->INC(INC);
		CTRL_Neuron->Load1(Load1);
		CTRL_Neuron->Load2(Load2);
		CTRL_Neuron->LoadRF(LoadRF);
		CTRL_Neuron->LoadACC(LoadACC);
		CTRL_Neuron->INIT1(INIT1);
		CTRL_Neuron->INIT2(INIT2);
		CTRL_Neuron->INIT_C(INIT_C);
		CTRL_Neuron->INIT_ACC(INIT_ACC);
		CTRL_Neuron->Start(Start);
		CTRL_Neuron->Done(Done_Int);

		SC_METHOD(assignment);
		sensitive << Done_Int;
	}

	void assignment();
};

template <int Address_Width, int Comp_Value>
void Single_Neuron<Address_Width, Comp_Value>::assignment()
{
	Done_OUT.write(Done_Int);
}



