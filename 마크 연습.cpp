#include "pch.h"
#include <iostream>
#include <CoalaMOD.h>
#pragma comment(lib, "CoalaMOD.lib")

int main()
{
	BlockID stone = createBlock(BLOCK_STONE);

	int sx, sy, sz, ex, ey, ez, bx, lx, by, ly, bz, lz, i, j, p, q, r;
	scanf_s("%d %d %d", &sx, &sy, &sz);
	scanf_s("%d %d %d", &ex, &ey, &ez);    // 양 끝 좌표 입력받기

	bx = sx > ex ? sx : ex;
	lx = sx < ex ? sx : ex;
	by = sy > ey ? sy : ey;
	ly = sy < ey ? sy : ey;
	bz = sz > ez ? sz : ez;
	lz = sz < ez ? sz : ez;     // 큰수 작은수 정해놓기 

	if (bx - lx < 2 || by - ly < 2 || bz - lz < 2)  // 건물 최소크기 3/3/3으로 정함
		printf("각각의 좌표 사이 거리가 2이상이 되도록 입력하세요. 종료합니다.");
	else
		locateBlock(stone, sx, ly, sz);  // 바닥층
		locateBlock(stone, sx, ly, ez);
		locateBlock(stone, ex, ly, sz);
		locateBlock(stone, ex, ly, ez);
		
		for (i = ly + 1; i < by; i++) {                // 중간층들 - y좌표 변화하면서
			for (j = lx; j < bx + 1; j++) {					// 중간층들 - 각 변
				locateBlock(stone, j, i, lz);
			}
			for (p = lx; p < bx + 1; p++) {					// 중간층들 - 변
				locateBlock(stone, p, i, bz);							  
			}															  
			for (q = lz; q < bz + 1; q++) {					// 중간층들 - 변
				locateBlock(stone, lx, i, q);							  
			}															  
			for (r = lz; r < bz + 1; r++) {					// 중간층들 - 변
				locateBlock(stone, bx, i, r);
			}
		}
		
		locateBlock(stone, sx, by, sz);  // 맨위층
		locateBlock(stone, sx, by, ez);
		locateBlock(stone, ex, by, sz);
		locateBlock(stone, ex, by, ez);
}



