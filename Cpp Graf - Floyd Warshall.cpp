#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

int main(){
	int N;
	int table[100][100];
	cout << "Program Menentukan Jarak Terpendek Antar Lokasi - Noviyana - 20200801048\n";
	cout << "========================================================================\n\n";
	cout << "Masukkan node (titik lokasi) yang diinginkan: ";
	cin >> N;
	cout << "Masukkan jarak antar node secara matriks (jika tidak ada jalan langsung, tulis 999) : \n";
	
	//misal jarak antara titik 1 dan 2 adalah 5, maka table[1][2] = 5
	//jika tidak ada jarak antar dua titik ditulis 0, misal table[1][1] = 0
	//jika tidak ada jalan langsung, tulis 999 (artinya tidak terbatas / belum diketahui)
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cin >> table[i][j];
			if(table[i][j]==999){
				table[i][j] = INT_MAX;
			}
		}
	}
	
	//perhitungan menggunakan algoritma floyd_warshall
	for(int k=1;k<=N;k++){
		for (int i=1;i<=N;i++){
			for(int j=1;j<=N;j++){
				if(table[i][k]==INT_MAX || table[k][j]==INT_MAX){
					continue;
				}
				else if(table[i][k]+table[k][j] < table[i][j]){
					table[i][j] = table[i][k]+table[k][j];
				}
			}
		}
	}
	cout << endl;
	
	//mengecek untuk edge weight cycle negatif
	for(int i=1;i<=N;i++){
		if(table[i][i] < 0){
			cout << "Jarak negatif ditemukan \n";
		}
	}
	
	//mencetak graf jarak terpendek
	//nilai berisi INT_MAX mendefinisikan tidak ada path (jalan) yang dapat dilalui
	
	for(int i=1;i<=N;i++){
		for(int j=1;j<=N;j++){
			cout << "Jarak antara titik " << i << " ke " << j << " adalah " << table[i][j] << "\n";
		}
		cout<<"=================================\n\n";
	}
}
