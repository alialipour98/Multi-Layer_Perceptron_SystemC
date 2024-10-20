#include "Top_Module_MLP_tb.h"

/*
* 	//  #include "LUT_tb.h"
	//	---------------------------------
	//	For LUT Testing
	//	---------------------------------
	LUT_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("LUTtest");

	sc_trace(vcdfile, tb.addr, "Adderss");
	sc_trace(vcdfile, tb.OUTPUT, "OUTPUT");

	sc_start(12000, SC_NS);
	return 0;
*/
/*
	//  #include "N_Bit_Counter_tb.h"
	//	---------------------------------
	//	For N_Bit_Counter Testing
	//	---------------------------------	
	N_Bit_Counter_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("nBitCounterTest");
	sc_trace(vcdfile, tb.Clock , "Clock");
	sc_trace(vcdfile, tb.Reset , "Reset");
	sc_trace(vcdfile, tb.INIT  , "INIT");
	sc_trace(vcdfile, tb.INC   , "INC");
	sc_trace(vcdfile, tb.OUTPUT, "OUTPUT");

	sc_start(12000, SC_NS);
	return 0;
*/
/*
	//  #include "Comparator_tb.h"
	//	---------------------------------
	//	For Comparator Testing
	//	---------------------------------
	Comparator_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("ComparatorTest");
	sc_trace(vcdfile, tb.INPUT_1, "INPUT_1");
	sc_trace(vcdfile, tb.INPUT_2, "INPUT_2");
	sc_trace(vcdfile, tb.EQ     , "EQ"     );

	sc_start(12000, SC_NS);
	return 0;
*/
/*
	//  #include "Register_src_tb.h"
	//	---------------------------------
	//	For Register Testing
	//	---------------------------------
	Register_src_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("Register");
	sc_trace(vcdfile, tb.Clock , "Clock" );
	sc_trace(vcdfile, tb.Reset , "Reset" );
	sc_trace(vcdfile, tb.Load  , "Load"  );
	sc_trace(vcdfile, tb.INIT  , "INIT"  );
	sc_trace(vcdfile, tb.INPUT , "INPUT" );
	sc_trace(vcdfile, tb.OUTPUT, "OUTPUT");

	sc_start(12000, SC_NS);
	return 0;
*/
/*
	//	#include "Adder_tb.h"
	//	---------------------------------
	//	For Adder Testing
	//	---------------------------------
	Adder_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("Adder");
	sc_trace(vcdfile, tb.INPUT_1, "INPUT_1");
	sc_trace(vcdfile, tb.INPUT_2, "INPUT_2");
	sc_trace(vcdfile, tb.OUTPUT , "OUTPUT");

	sc_start(12000, SC_NS);
	return 0;
*/
/*
	//	#include "Multiplier_tb.h"
	//	---------------------------------
	//	For Multiplier Testing
	//	---------------------------------
	Multiplier_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("Multiplier");
	sc_trace(vcdfile, tb.INPUT_1, "INPUT_1");
	sc_trace(vcdfile, tb.INPUT_2, "INPUT_2");
	sc_trace(vcdfile, tb.OUTPUT, "OUTPUT");

	sc_start(12000, SC_NS);
	return 0;
*/
/*
	//	#include "Register_File_tb.h"
	//	---------------------------------
	//	For Register File Testing
	//	---------------------------------
	Register_File_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("RegisterFileTest");
	sc_trace(vcdfile, tb.Clock  , "Clock"  );
	sc_trace(vcdfile, tb.Reset  , "Reset"  );
	sc_trace(vcdfile, tb.ReadEn , "ReadEn" );
	sc_trace(vcdfile, tb.Load   , "Load"   );
	sc_trace(vcdfile, tb.addr   , "Adderss");
	sc_trace(vcdfile, tb.INPUT_0, "INPUT_0");
	sc_trace(vcdfile, tb.INPUT_1, "INPUT_1");
	sc_trace(vcdfile, tb.INPUT_2, "INPUT_2");
	sc_trace(vcdfile, tb.INPUT_3, "INPUT_3");
	sc_trace(vcdfile, tb.INPUT_4, "INPUT_4");
	sc_trace(vcdfile, tb.INPUT_5, "INPUT_5");
	sc_trace(vcdfile, tb.INPUT_6, "INPUT_6");
	sc_trace(vcdfile, tb.INPUT_7, "INPUT_7");
	sc_trace(vcdfile, tb.INPUT_8, "INPUT_8");
	sc_trace(vcdfile, tb.INPUT_9, "INPUT_9");
	sc_trace(vcdfile, tb.OUTPUT , "OUTPUT" );

	sc_start(12000, SC_NS);
	return 0;
*/
/*
	//	#include "Multiplexer_tb.h"
	//	---------------------------------
	//	For Multiplexer Testing
	//	---------------------------------
	Multiplexer_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("Multiplexer");
	sc_trace(vcdfile, tb.INPUT_0, "INPUT_0");
	sc_trace(vcdfile, tb.INPUT_1, "INPUT_1");
	sc_trace(vcdfile, tb.SEL    , "SEL"    );
	sc_trace(vcdfile, tb.OUTPUT , "OUTPUT");

	sc_start(12000, SC_NS);
	return 0;
*/
/*
	//  #include "Address_Counter_tb.h"
	//	---------------------------------
	//	For Address Counter Testing
	//	---------------------------------
	Address_Counter_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("AddressCounterTest");
	sc_trace(vcdfile, tb.Clock , "Clock" );
	sc_trace(vcdfile, tb.Reset , "Reset" );
	sc_trace(vcdfile, tb.INIT  , "INIT"  );
	sc_trace(vcdfile, tb.INC   , "INC"   );
	sc_trace(vcdfile, tb.Done  , "Done"  );
	sc_trace(vcdfile, tb.OUTPUT, "OUTPUT");

	sc_start(12000, SC_NS);
	return 0;
*/
/*
	//  #include "Accumulator_tb.h"
	//	---------------------------------
	//	For Accumulator Register Testing
	//	---------------------------------
	Accumulator_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("AccRegister");
	sc_trace(vcdfile, tb.Clock  , "Clock"  );
	sc_trace(vcdfile, tb.Reset  , "Reset"  );
	sc_trace(vcdfile, tb.Load   , "Load"   );
	sc_trace(vcdfile, tb.INIT   , "INIT"   );
	sc_trace(vcdfile, tb.Bias_In, "Bias_In");
	sc_trace(vcdfile, tb.INPUT  , "INPUT"  );
	sc_trace(vcdfile, tb.OUTPUT , "OUTPUT" );

	sc_start(12000, SC_NS);
	return 0;
*/
/*
	//  #include "Single_Neuron_tb.h"
	//	---------------------------------
	//	For Single Neuron Testing
	//	---------------------------------
	Single_Neuron_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("Single Neuron");
	sc_trace(vcdfile, tb.Clock    , "Clock"    );
	sc_trace(vcdfile, tb.Reset    , "Reset"    );
	sc_trace(vcdfile, tb.Start    , "Start"    );
	sc_trace(vcdfile, tb.Done_OUT , "Done_OUT" );
	sc_trace(vcdfile, tb.INPUT_0  , "INPUT_0"  );
	sc_trace(vcdfile, tb.INPUT_1  , "INPUT_1"  );
	sc_trace(vcdfile, tb.INPUT_2  , "INPUT_2"  );
	sc_trace(vcdfile, tb.INPUT_3  , "INPUT_3"  );
	sc_trace(vcdfile, tb.INPUT_4  , "INPUT_4"  );
	sc_trace(vcdfile, tb.INPUT_5  , "INPUT_5"  );
	sc_trace(vcdfile, tb.INPUT_6  , "INPUT_6"  );
	sc_trace(vcdfile, tb.INPUT_7  , "INPUT_7"  );
	sc_trace(vcdfile, tb.INPUT_8  , "INPUT_8"  );
	sc_trace(vcdfile, tb.INPUT_9  , "INPUT_9"  );
	sc_trace(vcdfile, tb.Weight_0 , "Weight_0" );
	sc_trace(vcdfile, tb.Weight_1 , "Weight_1" );
	sc_trace(vcdfile, tb.Weight_2 , "Weight_2" );
	sc_trace(vcdfile, tb.Weight_3 , "Weight_3" );
	sc_trace(vcdfile, tb.Weight_4 , "Weight_4" );
	sc_trace(vcdfile, tb.Weight_5 , "Weight_5" );
	sc_trace(vcdfile, tb.Weight_6 , "Weight_6" );
	sc_trace(vcdfile, tb.Weight_7 , "Weight_7" );
	sc_trace(vcdfile, tb.Weight_8 , "Weight_8" );
	sc_trace(vcdfile, tb.Weight_9 , "Weight_9" );
	sc_trace(vcdfile, tb.Bias     , "Bias" );
	sc_trace(vcdfile, tb.OUTPUT_I , "OUTPUT_I" );
	sc_trace(vcdfile, tb.OUTPUT_II, "OUTPUT_II");

	sc_start(12000, SC_NS);
	return 0;
*/
/*
	//  #include "Controller_tb.h"
	//	---------------------------------
	//	For Controller Testing
	//	---------------------------------
	Controller_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("ControllerTest");
	sc_trace(vcdfile, tb.Clock, "Clock");
	sc_trace(vcdfile, tb.Reset, "Reset");
	sc_trace(vcdfile, tb.Start, "Start");
	sc_trace(vcdfile, tb.Done, "Done");
	sc_trace(vcdfile, tb.ReadRF, "ReadRF");
	sc_trace(vcdfile, tb.INC, "INC");
	sc_trace(vcdfile, tb.Load1, "Load1");
	sc_trace(vcdfile, tb.Load2, "Load2");
	sc_trace(vcdfile, tb.LoadRF, "LoadRF");
	sc_trace(vcdfile, tb.LoadACC, "LoadACC");
	sc_trace(vcdfile, tb.INIT1, "INIT1");
	sc_trace(vcdfile, tb.INIT2, "INIT2");
	sc_trace(vcdfile, tb.INIT_C, "INIT_C");
	sc_trace(vcdfile, tb.INIT_ACC, "INIT_ACC");

	sc_start(12000, SC_NS);
	return 0;
*/
/*
	//  #include "Single_Neuron_tb.h"
	//	---------------------------------
	//	For Single Neuron Testing
	//	---------------------------------
	Single_Neuron_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("Single Neuron");
	sc_trace(vcdfile, tb.Clock, "Clock");
	sc_trace(vcdfile, tb.Reset, "Reset");
	sc_trace(vcdfile, tb.Start, "Start");
	sc_trace(vcdfile, tb.SEL, "SEL");
	sc_trace(vcdfile, tb.ACC_O, "ACC_OUT");
	sc_trace(vcdfile, tb.Done_OUT, "Done_OUT");
	sc_trace(vcdfile, tb.INPUT_0, "INPUT_0");
	sc_trace(vcdfile, tb.INPUT_1, "INPUT_1");
	sc_trace(vcdfile, tb.INPUT_2, "INPUT_2");
	sc_trace(vcdfile, tb.INPUT_3, "INPUT_3");
	sc_trace(vcdfile, tb.INPUT_4, "INPUT_4");
	sc_trace(vcdfile, tb.INPUT_5, "INPUT_5");
	sc_trace(vcdfile, tb.INPUT_6, "INPUT_6");
	sc_trace(vcdfile, tb.INPUT_7, "INPUT_7");
	sc_trace(vcdfile, tb.INPUT_8, "INPUT_8");
	sc_trace(vcdfile, tb.INPUT_9, "INPUT_9");
	sc_trace(vcdfile, tb.Weight_0, "Weight_0");
	sc_trace(vcdfile, tb.Weight_1, "Weight_1");
	sc_trace(vcdfile, tb.Weight_2, "Weight_2");
	sc_trace(vcdfile, tb.Weight_3, "Weight_3");
	sc_trace(vcdfile, tb.Weight_4, "Weight_4");
	sc_trace(vcdfile, tb.Weight_5, "Weight_5");
	sc_trace(vcdfile, tb.Weight_6, "Weight_6");
	sc_trace(vcdfile, tb.Weight_7, "Weight_7");
	sc_trace(vcdfile, tb.Weight_8, "Weight_8");
	sc_trace(vcdfile, tb.Weight_9, "Weight_9");
	sc_trace(vcdfile, tb.Bias, "Bias");
	sc_trace(vcdfile, tb.OUTPUT_I, "OUTPUT_I");
	sc_trace(vcdfile, tb.OUTPUT_II, "OUTPUT_II");

	sc_start(12000, SC_NS);
	return 0;
*/
/*
	//  #include "Top_Module_MLP_tb.h"
	//	---------------------------------
	//	For Single Neuron Testing
	//	---------------------------------
	Top_Module_MLP_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("MLP_Top");
	sc_trace(vcdfile, tb.Clock  , "Clock"  );
	sc_trace(vcdfile, tb.Reset  , "Reset"  );
	sc_trace(vcdfile, tb.Start  , "Start"  );
	sc_trace(vcdfile, tb.Done   , "Done"   );
	sc_trace(vcdfile, tb.D_1    , "Done[0]");
	sc_trace(vcdfile, tb.INPUT_0, "INPUT_0");
	sc_trace(vcdfile, tb.INPUT_1, "INPUT_1");
	sc_trace(vcdfile, tb.INPUT_2, "INPUT_2");
	sc_trace(vcdfile, tb.INPUT_3, "INPUT_3");
	sc_trace(vcdfile, tb.OUTPUT , "OUTPUT" );
//	sc_trace(vcdfile, tb.OUTPUT_Test_0, "OUTPUT_I_I[0]");
//	sc_trace(vcdfile, tb.OUTPUT_Test_1, "OUTPUT_I_II[0]");
//	sc_trace(vcdfile, tb.mem_0, "mem_0");

	sc_start(12000, SC_NS);
	return 0;
*/
int sc_main(int argc, char** argv)
{
	//  #include "Top_Module_MLP_tb.h"
//	---------------------------------
//	For Single Neuron Testing
//	---------------------------------
	Top_Module_MLP_tb tb("TestBench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("MLP_Top");
	sc_trace(vcdfile, tb.Clock, "Clock");
	sc_trace(vcdfile, tb.Reset, "Reset");
	sc_trace(vcdfile, tb.Start, "Start");
	sc_trace(vcdfile, tb.Done, "Done");
	sc_trace(vcdfile, tb.D_1, "Done[0]");
	sc_trace(vcdfile, tb.INPUT_0, "INPUT_0");
	sc_trace(vcdfile, tb.INPUT_1, "INPUT_1");
	sc_trace(vcdfile, tb.INPUT_2, "INPUT_2");
	sc_trace(vcdfile, tb.INPUT_3, "INPUT_3");
	sc_trace(vcdfile, tb.OUTPUT, "OUTPUT");
	sc_trace(vcdfile, tb.Target, "Targer");
	//	sc_trace(vcdfile, tb.OUTPUT_Test_0, "OUTPUT_I_I[0]");
	//	sc_trace(vcdfile, tb.OUTPUT_Test_1, "OUTPUT_I_II[0]");
	//	sc_trace(vcdfile, tb.mem_0, "mem_0");

	sc_start(60000, SC_NS);
	return 0;
}
