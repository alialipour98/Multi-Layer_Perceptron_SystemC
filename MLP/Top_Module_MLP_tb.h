#include "Top_Module_MLP.h"

SC_MODULE(Top_Module_MLP_tb)
{
	sc_signal<sc_logic>    Clock;
	sc_signal<sc_logic>    Reset;
	sc_signal<sc_logic>    Start;
	sc_signal<sc_logic>     Done;

	sc_signal<sc_lv<8>>  INPUT_0;
	sc_signal<sc_lv<8>>  INPUT_1;
	sc_signal<sc_lv<8>>  INPUT_2;
	sc_signal<sc_lv<8>>  INPUT_3;

	sc_signal<sc_lv<2>>   OUTPUT;

	sc_signal<sc_lv<8>>   Test_Data[120];
	sc_signal<sc_lv<8>>   Target_Data[30];
	sc_signal<sc_lv<8>>   Target;

	int correct = 0;

//	sc_signal<sc_lv<8>>   OUTPUT_Test_0;
//	sc_signal<sc_lv<8>>   OUTPUT_Test_1;
//	sc_signal<sc_lv<8>>   OUTPUT_Test_2;
//	sc_signal<sc_lv<8>>   OUTPUT_Test_3;
//	sc_signal<sc_lv<8>>   OUTPUT_Test_4;
//	sc_signal<sc_lv<8>>   OUTPUT_Test_5;
//	sc_signal<sc_lv<8>>   OUTPUT_Test_6;
//	sc_signal<sc_lv<8>>   OUTPUT_Test_7;
//	sc_signal<sc_lv<8>>   OUTPUT_Test_8;
//	sc_signal<sc_lv<8>>   OUTPUT_Test_9;
//	sc_signal<sc_lv<8>>   mem_0;

	sc_signal<sc_logic>   D_1;
	sc_signal<sc_logic>   D_2;

	MLP* MLP_tb;

	SC_CTOR(Top_Module_MLP_tb)
	{
		MLP_tb = new MLP("MLP Testing");
		MLP_tb->Clock(Clock);
		MLP_tb->Reset(Reset);
		MLP_tb->Start(Start);
		MLP_tb->Done(Done);
		MLP_tb->INPUT_0(INPUT_0);
		MLP_tb->INPUT_1(INPUT_1);
		MLP_tb->INPUT_2(INPUT_2);
		MLP_tb->INPUT_3(INPUT_3);
		MLP_tb->OUTPUT(OUTPUT);
//		MLP_tb->D_Test_1(D_1);
//		MLP_tb->mem_Test(mem_0);
//		MLP_tb->OUTPUT_Test_0(OUTPUT_Test_0);
//		MLP_tb->OUTPUT_Test_1(OUTPUT_Test_1);
//		MLP_tb->OUTPUT_Test_2(OUTPUT_Test_2);
//		MLP_tb->OUTPUT_Test_3(OUTPUT_Test_3);
//		MLP_tb->OUTPUT_Test_4(OUTPUT_Test_4);
//		MLP_tb->OUTPUT_Test_5(OUTPUT_Test_5);
//		MLP_tb->OUTPUT_Test_6(OUTPUT_Test_6);
//		MLP_tb->OUTPUT_Test_7(OUTPUT_Test_7);
//		MLP_tb->OUTPUT_Test_8(OUTPUT_Test_8);
//		MLP_tb->OUTPUT_Test_9(OUTPUT_Test_9);
		
		SC_THREAD(clocking);
		SC_THREAD(inputing);
	}

	void clocking();
	void inputing();
};

void Top_Module_MLP_tb::clocking()
{
	while (true)
	{
		wait(5, SC_NS);
		Clock = SC_LOGIC_0;
		wait(5, SC_NS);
		Clock = SC_LOGIC_1;
	}
}
void Top_Module_MLP_tb::inputing()
{
	Reset = SC_LOGIC_0;
	Start = SC_LOGIC_0;
	
	int temp_0;
	int temp_1;

	std::ifstream test;
	test.open("X_Test_Data.txt");
	for (int i = 0; i < 120; i++)
	{
		test >> temp_0;
		Test_Data[i] = sc_lv<8>(temp_0);
	}

	std::ifstream target;
	target.open("Y_Test_Data.txt");
	for (int i = 0; i < 30; i++)
	{
		target >> temp_1;
		Target_Data[i] = sc_lv<2>(temp_1);
	}

	for (int i = 0; i < 30; i++)
	{
		Start = SC_LOGIC_1;
		wait(10, SC_NS);
		Start = SC_LOGIC_0;
		wait(10, SC_NS);

		INPUT_0 = sc_lv<8>(Test_Data[4 * i]);
		INPUT_1 = sc_lv<8>(Test_Data[4 * i + 1]);
		INPUT_2 = sc_lv<8>(Test_Data[4 * i + 2]);
		INPUT_3 = sc_lv<8>(Test_Data[4 * i + 3]);

		Target = Target_Data[i];

		wait(740, SC_NS);

		if (Done.read() == '1')
		{
			if (((sc_uint<2>)OUTPUT == (sc_uint<2>)Target_Data[i]))
				correct++;
		}

		wait(1000, SC_NS);
	}
	std::cout << "\n--------------------------------------------------------------------------- \n";
	std::cout << "Iris Dataset precision : ";
	std::cout << "Accuracy = " << (float)correct / 30;
	std::cout << "\n--------------------------------------------------------------------------- \n";
}
