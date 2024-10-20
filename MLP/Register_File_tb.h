#include "Register_File.h"

SC_MODULE(Register_File_tb)
{
	sc_signal<sc_logic> Clock;
	sc_signal<sc_logic> Reset;
	sc_signal<sc_logic> ReadEn;
	sc_signal<sc_logic> Load;

	sc_signal<sc_lv<4>>     addr;
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

	sc_signal<sc_lv<8>>  OUTPUT;

	Register_File<4, 8>* Reg;

	SC_CTOR(Register_File_tb)
	{
		Reg = new Register_File<4, 8>("Counter_8Bit");
		Reg->Clock(Clock);
		Reg->Reset(Reset);
		Reg->Load(Load);
		Reg->ReadEn(ReadEn);
		Reg->addr(addr);
		Reg->INPUT_0(INPUT_0);
		Reg->INPUT_1(INPUT_1);
		Reg->INPUT_2(INPUT_2);
		Reg->INPUT_3(INPUT_3);
		Reg->INPUT_4(INPUT_4);
		Reg->INPUT_5(INPUT_5);
		Reg->INPUT_6(INPUT_6);
		Reg->INPUT_7(INPUT_7);
		Reg->INPUT_8(INPUT_8);
		Reg->INPUT_9(INPUT_9);
		Reg->OUTPUT(OUTPUT);

		SC_THREAD(clocking);
		SC_THREAD(inputing);
	}

	void clocking();
	void inputing();
};

void Register_File_tb::clocking()
{
	while (true)
	{
		wait(10, SC_NS);
		Clock = SC_LOGIC_0;
		wait(10, SC_NS);
		Clock = SC_LOGIC_1;
	}
}
void Register_File_tb::inputing()
{
	ReadEn = SC_LOGIC_0;
	Load   = SC_LOGIC_0;

	Reset = SC_LOGIC_1;
	wait(10, SC_NS);
	Reset = SC_LOGIC_0;
	wait(10, SC_NS);

	INPUT_0 = "00100100"; // 036
	INPUT_1 = "00110100"; // 052
	INPUT_2 = "00111100"; // 060
	INPUT_3 = "00000100"; // 004
	INPUT_4 = "11100100"; // 228
	INPUT_5 = "00100111"; // 039
	INPUT_6 = "00100000"; // 032
	INPUT_7 = "01110100"; // 116
	INPUT_8 = "10100100"; // 164
	INPUT_9 = "01100100"; // 100
	wait(37, SC_NS);

	Load = SC_LOGIC_1;
	wait(10, SC_NS);
	Load = SC_LOGIC_0;
	wait(10, SC_NS);

	addr = "0000";

	wait(41, SC_NS);
	ReadEn = SC_LOGIC_1;
	wait(41, SC_NS);
	ReadEn = SC_LOGIC_0;
	wait(10, SC_NS);

	addr = "0001";

	wait(41, SC_NS);
	ReadEn = SC_LOGIC_1;
	wait(41, SC_NS);
	ReadEn = SC_LOGIC_0;
	wait(10, SC_NS);

	addr = "0010";
	wait(41, SC_NS);
	ReadEn = SC_LOGIC_1;
	wait(41, SC_NS);
	ReadEn = SC_LOGIC_0;
	wait(10, SC_NS);

	addr = "0011";

	wait(41, SC_NS);
	ReadEn = SC_LOGIC_1;
	wait(41, SC_NS);
	ReadEn = SC_LOGIC_0;
	wait(10, SC_NS);

	addr = "0100";

	wait(41, SC_NS);
	ReadEn = SC_LOGIC_1;
	wait(41, SC_NS);
	ReadEn = SC_LOGIC_0;
	wait(10, SC_NS);

	addr = "0101";

	wait(41, SC_NS);
	ReadEn = SC_LOGIC_1;
	wait(41, SC_NS);
	ReadEn = SC_LOGIC_0;
	wait(10, SC_NS);

	addr = "0110";

	wait(41, SC_NS);
	ReadEn = SC_LOGIC_1;
	wait(41, SC_NS);
	ReadEn = SC_LOGIC_0;
	wait(10, SC_NS);

	addr = "0111";

	wait(41, SC_NS);
	ReadEn = SC_LOGIC_1;
	wait(41, SC_NS);
	ReadEn = SC_LOGIC_0;
	wait(10, SC_NS);

	addr = "1000";

	wait(41, SC_NS);
	ReadEn = SC_LOGIC_1;
	wait(41, SC_NS);
	ReadEn = SC_LOGIC_0;
	wait(10, SC_NS);

	addr = "1001";

	wait(41, SC_NS);
	ReadEn = SC_LOGIC_1;
	wait(41, SC_NS);
	ReadEn = SC_LOGIC_0;

}
