#include <stdint.h>
#include <stdio.h>

#define NREG 4
#define NMEM 16

// ����ָ���ʽ
typedef union {
  struct { uint8_t rs : 2, rt : 2, op : 4; } rtype;
  struct { uint8_t addr : 4      , op : 4; } mtype;
  uint8_t inst;
} inst_t;

#define DECODE_R(inst) uint8_t rt = (inst).rtype.rt, rs = (inst).rtype.rs
#define DECODE_M(inst) uint8_t addr = (inst).mtype.addr

uint8_t pc = 0;       // PC, C������û��4λ����������, ���ǲ���8λ��������ʾ
uint8_t R[NREG] = {}; // �Ĵ���
uint8_t M[NMEM] = {   // �ڴ�, ���а���һ������z = x + y�ĳ���
  0b11100110,  // load  6#     | R[0] <- M[y]
  0b00000100,  // mov   r1, r0 | R[1] <- R[0]
  0b11100101,  // load  5#     | R[0] <- M[x]
  0b00010001,  // add   r0, r1 | R[0] <- R[0] + R[1]
  0b11110111,  // store 7#     | M[z] <- R[0]
  0b00010000,  // x = 16
  0b00100001,  // y = 33
  0b00000000,  // z = 0
};

int halt = 0; // ������־

// ִ��һ��ָ��
void exec_once() {
  inst_t thi;
  thi.inst = M[pc]; // ȡָ
  switch (thi.rtype.op) {
  //  ����������       ����������           ִ��
    case 0b0000: { DECODE_R(thi); R[rt]   = R[rs];   break; }
    case 0b0001: { DECODE_R(thi); R[rt]  += R[rs];   break; }
    case 0b1110: { DECODE_M(thi); R[0]    = M[addr]; break; }
    case 0b1111: { DECODE_M(thi); M[addr] = R[0];    break; }
    default:
      printf("Invalid instruction with opcode = %x, halting...\n", thi.rtype.op);
      halt = 1;
      break;
  }
  pc ++; // ����PC
}

int main() {
	printf("{%d", pc);
	for (int i = 0; i < 2; i++)
		printf(",%d", R[i]); 
	for (int i = 5; i < 8; i++)
		printf(",%d", M[i]);
	printf("}\n");
  while (1) {
    exec_once();
    printf("{%d", pc);
	for (int i = 0; i < 2; i++)
		printf(",%d", R[i]); 
	for (int i = 5; i < 8; i++)
		printf(",%d", M[i]);
	printf("}\n");
    if (halt) break;
  }
  printf("The result of 16 + 33 is %d\n", M[7]);
  return 0;
}
