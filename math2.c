#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>	
#define W 8
#define H 6

int main(void) {
	int vec [H][W] =
	{ 1,1,0,0,0,0,0,220,
	0,1,-1,0,-1,0,0,60,
	0,0,0,0,1,-1,0,40,
	1,0,0,-1,0,0,0,40,
	0,0,1,1,0,0,-1,50,
	0,0,0,0,0,1,1, 30 };

	//���� �ٲٴ� ����
	int buffer[W] = { 0 };
	int i = 0; //��
	int j = 0; //��
	int w_i = 0;

	for (w_i = 0; w_i < H; w_i++) {
		for (i = 0; i < H - 1; i++) {
			if (vec[i][i] != 1 && vec[i + 1][i] != 1) {
				if (vec[i][i + 1] <= vec[i + 1][i + 1]) {
					
				}
				else {
					for (j = 0; j < 8; j++) {
						buffer[j] = vec[i][j];
						vec[i][j] = vec[i + 1][j];
						vec[i + 1][j] = buffer[j];
					}
				}
			}
			else {
				if (vec[i][i] >= vec[i + 1][i]) {

				}
				else {
					for (j = 0; j < 8; j++) {
						buffer[j] = vec[i][j];
						vec[i][j] = vec[i + 1][j];
						vec[i + 1][j] = buffer[j];
					}
				}
			}
		}
	}

	//�� ��ȣ �ٲٴ� ����

	int Wbuffer[8] = { 0 };
	int h = 0; //buffer�� ���� �� ã���� ��
	int ibuf = 0; //buffer�� �� �����Ҷ� ��
	int h2 = 0; //���� ������ �� ã�� �� ��
	int w = 0; //�������꿡�� ����ü �����Ҷ� ��


	for (i = 0; i < H - 1; i++) {
		if (vec[i][i] != 1) {
			for (h = 0; h < 6; h++) {
				if (vec[i][i] == vec[i + 1][i]) {
					for (ibuf = 0; ibuf < 8; ibuf++) {
						Wbuffer[ibuf] = vec[i + 1][ibuf];
					}
				}
			}
			if (vec[i][i] != vec[i + 1][i]) {
				for (ibuf = 0; ibuf < 8; ibuf++) {
					vec[i][ibuf] = -vec[i][ibuf];
				}
			}
		}
	}

	int roof1 = 0; //while�� ��
	int roof2 = 0; //while�� ��
	//�ೢ�� �������� 
	for (roof1 = 0; roof1 < H; roof1++) {
		for (roof2 = 0; roof2 < roof1; roof2++) {
			while (vec[roof1][roof2] != 0) {
				for (i = 0; i < H; i++) {
					for (j = 0; j < i; j++) {
						if (vec[i][j] != 0 && vec[i][i] == 1) {
							for (h2 = 0; h2 < H; h2++) {
								if (-vec[i][j] == vec[h2][j]) {
									if (vec[i][j] < vec[h2][j]) { //�� ����
										while (vec[i][j] != 0) {
											for (w = 0; w < W; w++) {
												vec[i][w] += vec[h2][w];
											}
										}
									}
									else {//�� ����
										while (vec[i][j] != 0) {
											for (w = 0; w < W; w++) {
												vec[i][w] -= vec[h2][w];
											}
										}
									}
								}
							}
						}
					}

				}
			}
		}
	}
	

	
	
	for (i = 0; i < 6; i++) {
		for (j = 0; j < 8; j++) {
			printf("%d", vec[i][j]);
		}
		printf("\n");
	}
	return 0;
}