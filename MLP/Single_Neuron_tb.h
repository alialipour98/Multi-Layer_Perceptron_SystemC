#include "Single_Neuron.h"

SC_MODULE(Single_Neuron_tb)
{
	sc_signal<sc_logic>    Clock;
	sc_signal<sc_logic>    Reset;
	sc_signal<sc_logic>    Start;
	sc_signal<sc_logic> Done_OUT;

	sc_signal<sc_logic>      SEL;

	sc_signal<sc_lv<8>>  INPUT_0;
	sc_signal<sc_lv<8>>  INPUT_1;
	sc_signal<sc_lv<8>>  INPUT_2;
	sc_signal<sc_lv<8>>  INPUT_3;
	sc_signal<sc_lv<8>>  INPUT_4;
	sc_signal<sc_lv<8>>  INPUT_5;
	sc_signal<sc_lv<8>>  INPUT_6;
	sc_signal<sc_lv<8>>  INPUT_7;
	sc_signal<sc_lv<8>>  INPUT_8;
	sc_signal<sc_lv<8>>  INPUT_9;

	sc_signal<sc_lv<8>>  Weight_0;
	sc_signal<sc_lv<8>>  Weight_1;
	sc_signal<sc_lv<8>>  Weight_2;
	sc_signal<sc_lv<8>>  Weight_3;
	sc_signal<sc_lv<8>>  Weight_4;
	sc_signal<sc_lv<8>>  Weight_5;
	sc_signal<sc_lv<8>>  Weight_6;
	sc_signal<sc_lv<8>>  Weight_7;
	sc_signal<sc_lv<8>>  Weight_8;
	sc_signal<sc_lv<8>>  Weight_9;

	sc_signal<sc_lv<8>>  Bias;

	sc_signal<sc_lv<8>>  OUTPUT_I;
	sc_signal<sc_lv<8>>  OUTPUT_II;

	sc_signal<sc_lv<16>>  ACC_O;

	Single_Neuron<4, 4>* SN;

	SC_CTOR(Single_Neuron_tb)
	{
		SN = new Single_Neuron<4, 4>("Single Neuron");
		SN->Clock(Clock);
		SN->Reset(Reset);
		SN->Start(Start);
		SN->Done_OUT(Done_OUT);
		SN->INPUT_0(INPUT_0);
		SN->INPUT_1(INPUT_1);
		SN->INPUT_2(INPUT_2);
		SN->INPUT_3(INPUT_3);
		SN->INPUT_4(INPUT_4);
		SN->INPUT_5(INPUT_5);
		SN->INPUT_6(INPUT_6);
		SN->INPUT_7(INPUT_7);
		SN->INPUT_8(INPUT_8);
		SN->INPUT_9(INPUT_9);
		SN->Weight_0(Weight_0);
		SN->Weight_1(Weight_1);
		SN->Weight_2(Weight_2);
		SN->Weight_3(Weight_3);
		SN->Weight_4(Weight_4);
		SN->Weight_5(Weight_5);
		SN->Weight_6(Weight_6);
		SN->Weight_7(Weight_7);
		SN->Weight_8(Weight_8);
		SN->Weight_9(Weight_9);
		SN->Bias(Bias);
		SN->OUTPUT_I(OUTPUT_I);
		SN->OUTPUT_II(OUTPUT_II);

		SC_THREAD(clocking);
		SC_THREAD(inputing);
	}

	void clocking();
	void inputing();
};

void Single_Neuron_tb::clocking()
{
	while (true)
	{
		wait(5, SC_NS);
		Clock = SC_LOGIC_0;
		wait(5, SC_NS);
		Clock = SC_LOGIC_1;
	}
}
void Single_Neuron_tb::inputing()
{
	Start = SC_LOGIC_0;
	Reset = SC_LOGIC_1;
	wait(10, SC_NS);
	Reset = SC_LOGIC_0;
	wait(10, SC_NS);

	INPUT_0 = sc_lv<8>(57);
	INPUT_1 = sc_lv<8>(30);
	INPUT_2 = sc_lv<8>(42);
	INPUT_3 = sc_lv<8>(12);
	INPUT_4 = sc_lv<8>(0);
	INPUT_5 = sc_lv<8>(0);
	INPUT_6 = sc_lv<8>(0);
	INPUT_7 = sc_lv<8>(0);
	INPUT_8 = sc_lv<8>(0);
	INPUT_9 = sc_lv<8>(0);
	
	Weight_0 = sc_lv<8>(-3);
	Weight_1 = sc_lv<8>(5);
	Weight_2 = sc_lv<8>(33);
	Weight_3 = sc_lv<8>(54);
	Weight_4 = sc_lv<8>(0);
	Weight_5 = sc_lv<8>(0);
	Weight_6 = sc_lv<8>(0);
	Weight_7 = sc_lv<8>(0);
	Weight_8 = sc_lv<8>(0);
	Weight_9 = sc_lv<8>(0);

	Bias     = sc_lv<8>(-10);

	Start = SC_LOGIC_1;
	wait(50, SC_NS);
	Start = SC_LOGIC_0;
	wait(50, SC_NS);

}
