#include <systemc.h>
#include <fstream>
#include "Single_Neuron.h"

SC_MODULE(MLP)
{
	sc_in     <sc_logic>    Clock;
	sc_in     <sc_logic>    Reset;
	sc_in     <sc_logic>    Start;
	sc_out    <sc_logic>     Done;

	sc_in    <sc_lv<8>>   INPUT_0;
	sc_in    <sc_lv<8>>   INPUT_1;
	sc_in    <sc_lv<8>>   INPUT_2;
	sc_in    <sc_lv<8>>   INPUT_3;

	sc_out    <sc_lv<2>>   OUTPUT;

//	sc_out    <sc_lv<8>>   OUTPUT_Test_0;
//	sc_out    <sc_lv<8>>   OUTPUT_Test_1;
//	sc_out    <sc_lv<8>>   OUTPUT_Test_2;
//	sc_out    <sc_lv<8>>   OUTPUT_Test_3;
//	sc_out    <sc_lv<8>>   OUTPUT_Test_4;
//	sc_out    <sc_lv<8>>   OUTPUT_Test_5;
//	sc_out    <sc_lv<8>>   OUTPUT_Test_6;
//	sc_out    <sc_lv<8>>   OUTPUT_Test_7;
//	sc_out    <sc_lv<8>>   OUTPUT_Test_8;
//	sc_out    <sc_lv<8>>   OUTPUT_Test_9;
//	sc_out    <sc_lv<8>>   mem_Test;
//	sc_out    <sc_logic>   D_Test_1;

	sc_signal <sc_logic>  Done_I[10];
	sc_signal <sc_logic>  Done_II[8];
	sc_signal <sc_logic> Done_III[3];

	sc_signal <sc_lv<8>>   Zero;

/*
	sc_signal <sc_lv<8>> mem[165] = {
	  sc_lv < 8>(11 ), 
	  sc_lv < 8>(-11), 
	  sc_lv < 8>(-60), 
	  sc_lv < 8>(-8 ),
	  sc_lv < 8>(-35),
	  sc_lv < 8>(-26), 
	  sc_lv < 8>(-12),
	  sc_lv < 8>(34 ),
	  sc_lv < 8>(-3 ),
	  sc_lv < 8>(5  ), 
	  sc_lv < 8>(33 ),
	  sc_lv < 8>(54 ),
	  sc_lv < 8>(37 ),
	  sc_lv < 8>(-9 ), 
	  sc_lv < 8>(-39),
	  sc_lv < 8>(3  ),
	  sc_lv < 8>(-6 ),
	  sc_lv < 8>(25 ),
	  sc_lv < 8>(-12),
	  sc_lv < 8>(16 ),
	  sc_lv < 8>(-24),
	  sc_lv < 8>(-15),
	  sc_lv < 8>(-11),
	  sc_lv < 8>(48 ),
	  sc_lv < 8>(-19),
	  sc_lv < 8>(6  ), 
	  sc_lv < 8>(3  ),
	  sc_lv < 8>(-34),
	  sc_lv < 8>(21 ),
	  sc_lv < 8>(-41),
	  sc_lv < 8>(6  ),
	  sc_lv < 8>(3  ),
	  sc_lv < 8>(-30),
	  sc_lv < 8>(65 ),
	  sc_lv < 8>(0  ), 
	  sc_lv < 8>(-18),
	  sc_lv < 8>(-62),
	  sc_lv < 8>(-2 ), 
	  sc_lv < 8>(-12),
	  sc_lv < 8>(-5 ),
	  sc_lv < 8>(13 ),
	  sc_lv < 8>(-46),
	  sc_lv < 8>(-42),
	  sc_lv < 8>(16 ),
	  sc_lv < 8>(-21), 
	  sc_lv < 8>(28 ), 
	  sc_lv < 8>(-33),
	  sc_lv < 8>(32 ),
	  sc_lv < 8>(-37), 
	  sc_lv < 8>(-42),
	  sc_lv < 8>(12 ), 
	  sc_lv < 8>(-19),
	  sc_lv < 8>(27 ),
	  sc_lv < 8>(54 ), 
	  sc_lv < 8>(46 ), 
	  sc_lv < 8>(-35),
	  sc_lv < 8>(10 ),
	  sc_lv < 8>(37 ), 
	  sc_lv < 8>(-9 ),
	  sc_lv < 8>(-39),
	  sc_lv < 8>(56 ),
	  sc_lv < 8>(-46),
	  sc_lv < 8>(-9 ), 
	  sc_lv < 8>(-40),
	  sc_lv < 8>(15 ),
	  sc_lv < 8>(25 ), 
	  sc_lv < 8>(13 ), 
	  sc_lv < 8>(-44),
	  sc_lv < 8>(-27),
	  sc_lv < 8>(47 ), 
	  sc_lv < 8>(-53),
	  sc_lv < 8>(-15),
	  sc_lv < 8>(-3 ),
	  sc_lv < 8>(-27),
	  sc_lv < 8>(27 ), 
	  sc_lv < 8>(-8 ),
	  sc_lv < 8>(32 ),
	  sc_lv < 8>(39 ),
	  sc_lv < 8>(13 ), 
	  sc_lv < 8>(15 ),
	  sc_lv < 8>(-17),
	  sc_lv < 8>(22 ),
	  sc_lv < 8>(-42),
	  sc_lv < 8>(15 ),
	  sc_lv < 8>(-24),
	  sc_lv < 8>(11 ), 
	  sc_lv < 8>(47 ), 
	  sc_lv < 8>(-17),
	  sc_lv < 8>(-59),
	  sc_lv < 8>(20 ), 
	  sc_lv < 8>(-49),
	  sc_lv < 8>(-18),
	  sc_lv < 8>(45 ),
	  sc_lv < 8>(14 ),
	  sc_lv < 8>(-14),
	  sc_lv < 8>(46 ),
	  sc_lv < 8>(7  ),
	  sc_lv < 8>(17 ), 
	  sc_lv < 8>(-17),
	  sc_lv < 8>(8  ),
	  sc_lv < 8>(45 ), 
	  sc_lv < 8>(-50),
      sc_lv < 8>(44 ),
	  sc_lv < 8>(50 ),
	  sc_lv < 8>(9  ),
      sc_lv < 8>(36 ), 
	  sc_lv < 8>(9  ),
	  sc_lv < 8>(-54),
	  sc_lv < 8>(73 ), 
	  sc_lv < 8>(-19), 
	  sc_lv < 8>(24 ), 
	  sc_lv < 8>(23 ),
	  sc_lv < 8>(32 ), 
	  sc_lv < 8>(-39),
	  sc_lv < 8>(-51),
	  sc_lv < 8>(-37),
	  sc_lv < 8>(-57),
	  sc_lv < 8>(-44),
	  sc_lv < 8>(3  ),
	  sc_lv < 8>(-16),
	  sc_lv < 8>(-89),
	  sc_lv < 8>(-47), 
	  sc_lv < 8>(-44), 
	  sc_lv < 8>(6  ),
	  sc_lv < 8>(-16),
	  sc_lv < 8>(3  ), 
	  sc_lv < 8>(34 ),
	  sc_lv < 8>(-57),
	  sc_lv < 8>(21 ),
	  sc_lv < 8>(-48),
	  sc_lv < 8>(67 ),
	  sc_lv < 8>(-61),
	  sc_lv < 8>(8  ), 
	  sc_lv < 8>(37 ), 
	  sc_lv < 8>(0  ),
	  sc_lv < 8>(20 ),
	  sc_lv < 8>(-29),
	  sc_lv < 8>(-67),
	  sc_lv < 8>(31 ),
	  sc_lv < 8>(56 ),
	  sc_lv < 8>(73 ),
	  sc_lv < 8>(49 ),
	  sc_lv < 8>(-11), 
	  sc_lv < 8>(46 ),
	  sc_lv < 8>(0  ),
	  sc_lv < 8>(0  ),
	  sc_lv < 8>(-10),
	  sc_lv < 8>(16 ),
	  sc_lv < 8>(-17),
	  sc_lv < 8>(0  ),
	  sc_lv < 8>(0  ), 
	  sc_lv < 8>(-17),
	  sc_lv < 8>(0  ),
	  sc_lv < 8>(0  ), 
	  sc_lv < 8>(31 ), 
	  sc_lv < 8>(29 ),
	  sc_lv < 8>(-17),
	  sc_lv < 8>(-21),
	  sc_lv < 8>(3  ),
	  sc_lv < 8>(-17),
	  sc_lv < 8>(33 ),
	  sc_lv < 8>(-25),
	  sc_lv < 8>(15 ),
	  sc_lv < 8>(24 ),
	  sc_lv < 8>(-22)};
*/

	sc_signal <sc_lv<8>> mem[165];

//	sc_signal<sc_lv<8>>* OUTPUT_I_I;
//	sc_signal<sc_lv<8>>* OUTPUT_I_II;
//	sc_signal<sc_lv<8>>* OUTPUT_I_III;

	sc_signal<sc_lv<8>> OUTPUT_I_I[10];
	sc_signal<sc_lv<8>> OUTPUT_I_II[8];
	sc_signal<sc_lv<8>> OUTPUT_I_III[3];

//	sc_signal<sc_lv<8>>* OUTPUT_II_I;
//	sc_signal<sc_lv<8>>* OUTPUT_II_II;
//	sc_signal<sc_lv<8>>* OUTPUT_II_III;

	sc_signal<sc_lv<8>> OUTPUT_II_I[10];
	sc_signal<sc_lv<8>> OUTPUT_II_II[8];
	sc_signal<sc_lv<8>> OUTPUT_II_III[3];

//  ------------------------------------  //
	
	Single_Neuron<4, 4>*    Neuron_I[10];
	Single_Neuron<4, 10>*   Neuron_II[8];
	Single_Neuron<4, 8>*   Neuron_III[3];

	SC_CTOR(MLP)
	{
//		OUTPUT_I_I    = new sc_signal<sc_lv<8>>[10];
//		OUTPUT_II_I   = new sc_signal<sc_lv<8>>[10];

//		OUTPUT_I_II   = new sc_signal<sc_lv<8>>[8];
//		OUTPUT_II_II  = new sc_signal<sc_lv<8>>[8];

//		OUTPUT_I_III  = new sc_signal<sc_lv<8>>[3];
//		OUTPUT_II_III = new sc_signal<sc_lv<8>>[3];

		// Layer I
		for (int i = 0; i < 10; i++)
		{
			Neuron_I[i] = new Single_Neuron<4, 4>(("Neuron I_" + std::to_string(i)).c_str());
			Neuron_I[i]->Clock(Clock);
			Neuron_I[i]->Reset(Reset);
			Neuron_I[i]->Start(Start);
			Neuron_I[i]->Done_OUT(Done_I[i]);
			Neuron_I[i]->INPUT_0(INPUT_0);
			Neuron_I[i]->INPUT_1(INPUT_1);
			Neuron_I[i]->INPUT_2(INPUT_2);
			Neuron_I[i]->INPUT_3(INPUT_3);
			Neuron_I[i]->INPUT_4(Zero);
			Neuron_I[i]->INPUT_5(Zero);
			Neuron_I[i]->INPUT_6(Zero);
			Neuron_I[i]->INPUT_7(Zero);
			Neuron_I[i]->INPUT_8(Zero);
			Neuron_I[i]->INPUT_9(Zero);
			Neuron_I[i]->Weight_0(mem[4 * i]);
			Neuron_I[i]->Weight_1(mem[4 * i + 1]);
			Neuron_I[i]->Weight_2(mem[4 * i + 2]);
			Neuron_I[i]->Weight_3(mem[4 * i + 3]);
			Neuron_I[i]->Weight_4(Zero);
			Neuron_I[i]->Weight_5(Zero);
			Neuron_I[i]->Weight_6(Zero);
			Neuron_I[i]->Weight_7(Zero);
			Neuron_I[i]->Weight_8(Zero);
			Neuron_I[i]->Weight_9(Zero);
			Neuron_I[i]->Bias(mem[i + 144]);
			Neuron_I[i]->OUTPUT_I(OUTPUT_I_I[i]);
			Neuron_I[i]->OUTPUT_II(OUTPUT_II_I[i]);
		}

		// Layer II
		for (int j = 0; j < 8; j++)
		{
			Neuron_II[j] = new Single_Neuron<4, 10>(("Neuron II_" + std::to_string(j)).c_str());
			Neuron_II[j]->Clock(Clock);
			Neuron_II[j]->Reset(Reset);
			Neuron_II[j]->Start(Done_I[9]);
			Neuron_II[j]->Done_OUT(Done_II[j]);
			Neuron_II[j]->INPUT_0(OUTPUT_I_I[0]);
			Neuron_II[j]->INPUT_1(OUTPUT_I_I[1]);
			Neuron_II[j]->INPUT_2(OUTPUT_I_I[2]);
			Neuron_II[j]->INPUT_3(OUTPUT_I_I[3]);
			Neuron_II[j]->INPUT_4(OUTPUT_I_I[4]);
			Neuron_II[j]->INPUT_5(OUTPUT_I_I[5]);
			Neuron_II[j]->INPUT_6(OUTPUT_I_I[6]);
			Neuron_II[j]->INPUT_7(OUTPUT_I_I[7]);
			Neuron_II[j]->INPUT_8(OUTPUT_I_I[8]);
			Neuron_II[j]->INPUT_9(OUTPUT_I_I[9]);
			Neuron_II[j]->Weight_0(mem[40 + 10 * j]);
			Neuron_II[j]->Weight_1(mem[40 + 10 * j + 1]);
			Neuron_II[j]->Weight_2(mem[40 + 10 * j + 2]);
			Neuron_II[j]->Weight_3(mem[40 + 10 * j + 3]);
			Neuron_II[j]->Weight_4(mem[40 + 10 * j + 4]);
			Neuron_II[j]->Weight_5(mem[40 + 10 * j + 5]);
			Neuron_II[j]->Weight_6(mem[40 + 10 * j + 6]);
			Neuron_II[j]->Weight_7(mem[40 + 10 * j + 7]);
			Neuron_II[j]->Weight_8(mem[40 + 10 * j + 8]);
			Neuron_II[j]->Weight_9(mem[40 + 10 * j + 9]);
			Neuron_II[j]->Bias(mem[j + 144 + 10]);
			Neuron_II[j]->OUTPUT_I(OUTPUT_I_II[j]);
			Neuron_II[j]->OUTPUT_II(OUTPUT_II_II[j]);
		}

		// Layer III
		for (int k = 0; k < 3; k++)
		{
			Neuron_III[k] = new Single_Neuron<4, 8>(("Neuron III_" + std::to_string(k)).c_str());
			Neuron_III[k]->Clock(Clock);
			Neuron_III[k]->Reset(Reset);
			Neuron_III[k]->Start(Done_II[7]);
			Neuron_III[k]->Done_OUT(Done_III[k]);
			Neuron_III[k]->INPUT_0(OUTPUT_I_II[0]);
			Neuron_III[k]->INPUT_1(OUTPUT_I_II[1]);
			Neuron_III[k]->INPUT_2(OUTPUT_I_II[2]);
			Neuron_III[k]->INPUT_3(OUTPUT_I_II[3]);
			Neuron_III[k]->INPUT_4(OUTPUT_I_II[4]);
			Neuron_III[k]->INPUT_5(OUTPUT_I_II[5]);
			Neuron_III[k]->INPUT_6(OUTPUT_I_II[6]);
			Neuron_III[k]->INPUT_7(OUTPUT_I_II[7]);
			Neuron_III[k]->INPUT_8(Zero);
			Neuron_III[k]->INPUT_9(Zero);
			Neuron_III[k]->Weight_0(mem[120 + 8 * k]);
			Neuron_III[k]->Weight_1(mem[120 + 8 * k + 1]);
			Neuron_III[k]->Weight_2(mem[120 + 8 * k + 2]);
			Neuron_III[k]->Weight_3(mem[120 + 8 * k + 3]);
			Neuron_III[k]->Weight_4(mem[120 + 8 * k + 4]);
			Neuron_III[k]->Weight_5(mem[120 + 8 * k + 5]);
			Neuron_III[k]->Weight_6(mem[120 + 8 * k + 6]);
			Neuron_III[k]->Weight_7(mem[120 + 8 * k + 7]);
			Neuron_III[k]->Weight_8(Zero);
			Neuron_III[k]->Weight_9(Zero);
			Neuron_III[k]->Bias(mem[k + 144 + 10 + 8]);
			Neuron_III[k]->OUTPUT_I(OUTPUT_I_III[k]);
			Neuron_III[k]->OUTPUT_II(OUTPUT_II_III[k]);
		}

		SC_METHOD(assignment);
		sensitive << Done_III[2] << OUTPUT_II_I[0] << OUTPUT_II_II[0] << mem[40] << Done_I[0];

		SC_METHOD(serialGeneration);

	}

	void assignment();
	void serialGeneration();
};

void MLP::assignment()
{
	Done.write(Done_III[2]);
//	D_Test_1.write(Done_I[0]);
//	mem_Test.write(mem[11]);

//	OUTPUT_Test_0.write(OUTPUT_II_I[0]);
//	OUTPUT_Test_1.write(OUTPUT_II_II[0]);
//	OUTPUT_Test_2.write(OUTPUT_II_I[2]);
//	OUTPUT_Test_3.write(OUTPUT_II_I[3]);
//	OUTPUT_Test_4.write(OUTPUT_II_I[4]);
//	OUTPUT_Test_5.write(OUTPUT_II_I[5]);
//	OUTPUT_Test_6.write(OUTPUT_II_I[6]);
//	OUTPUT_Test_7.write(OUTPUT_II_I[7]);
//	OUTPUT_Test_8.write(OUTPUT_II_I[8]);
//	OUTPUT_Test_9.write(OUTPUT_II_I[9]);

	Zero.write(sc_lv<8>(0));

	if (Done_III[2] == SC_LOGIC_1)
	{
		if (((sc_int<8>)OUTPUT_II_III[0] > (sc_int<8>)OUTPUT_II_III[1]) && ((sc_int<8>)OUTPUT_II_III[0] > (sc_int<8>)OUTPUT_II_III[2]))
			OUTPUT.write("00");
		else if (((sc_int<8>)OUTPUT_II_III[1] > (sc_int<8>)OUTPUT_II_III[0]) && ((sc_int<8>)OUTPUT_II_III[1] > (sc_int<8>)OUTPUT_II_III[2]))
			OUTPUT.write("01");
		else if (((sc_int<8>)OUTPUT_II_III[2] > (sc_int<8>)OUTPUT_II_III[1]) && ((sc_int<8>)OUTPUT_II_III[2] > (sc_int<8>)OUTPUT_II_III[0]))
			OUTPUT.write("10");
	}

}

void MLP::serialGeneration()
{
	int temp;
	std::ifstream fp;
	fp.open("ROM_WB.txt");
	for (int i = 0; i < 165; i++)
	{
		fp >> temp;
		mem[i] = sc_lv<8>(temp);
	}

}




