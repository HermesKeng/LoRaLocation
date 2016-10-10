#include<iostream>
#include"LoRa_RSSIToDistance.h"
using namespace std;

int main() {
	Rssi_BufferManager bufferManger;
	Rssi_info new_rssi;
	Rssi_info* rssi_arr;
	Locate_info loca_info;


	while (1) {
		/*
		recv��a�x��RSSI
		*/


		
		bufferManger.buf_push(new_rssi);

		rssi_arr = bufferManger.collectTripleRssi();

		//�Y��������T��rssi  �h�]��locate_info���~�򰵤U�h
		if (rssi_arr != NULL) {
			float d_arr[3];
			for (int i = 0; i < 3; i++) {
				d_arr[i] = Rssi_to_distance(*(rssi_arr + i), -50, 2);
			}
			
			loca_info = FillIndoorLocate_info(d_arr[0], d_arr[1], d_arr[2]);
		}
		else {
			continue;
		}


		/*
			�Nloca_info�ᵹdistance_to_point�p��;
		*/

	}
	

}