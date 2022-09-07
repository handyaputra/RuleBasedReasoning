#include <bits/stdc++.h>

#define Handy using
#define Adi namespace
#define Putra std

Handy Adi Putra;

//init result function per status
double calc(double ans[], double cf[]){
	int i,j;			//iterator
	int jml_ciri = 10;	//jumlah ciri-ciri
	double res = 0;			//store result
	
	//cf calc loop
	for(i=1; i<jml_ciri; i++){
		res += (cf[i] * ans[i]) * (1 - res);
	}
	
	res *= 100;	//percentage
	
	return res;	//return
}

int main() {
	//variable controls
	int i,j;	//iterator
	int xi;		//store 0-5 ans
	char xc;	//store y/n ans
	
	int jml_ciri = 10;	//jumlah ciri-ciri
	
	double ans[10];		//store cf user
	
	int jml_res = 13;	//jumlah kemungkinan
	double res[12];		//store all cf result
	
	double cek_s01;		//cek ciri S01 - Biasa
	
	//init ciri-ciri
	string ciris[jml_ciri] = {
		"Apakah anda pernah melakukan tes PCR?",
		"Apakah daerah tempat tinggal anda\n merupakan zona merah COVID-19?",
		"Apakah anda telah melakukan perjalanan\n dari luar kota dalam 14 hari terakhir?",
		"Apakah anda sempat melakukan kontak dengan\n seseorang yang terkonfirmasi Positif COVID-19?",
		"Apakah anda memiliki riwayat atau gejala demam (>= 38o Celcius)?",
		"Apakah anda memiliki riwayat atau gangguan penyakit\n pernafasan (Pilek, Sakit Tenggorokan, Batuk, dsb)?",
		"Apakah anda memiliki riwayat atau mengidap penyakit\n ISPA (Infeksi Saluran Pernafasan Akut)?",
		"Apakah anda tidak memiliki gejala atau gangguan penyakit lain\n selain yang ada diatas?",
		"Apakah anda memiliki riwayat penyakit yang membutuhkan\n perawatan di Rumah Sakit?",
		"Apakah anda memiliki hasil Positif pada Tes PCR?"
	};
	
	//init result status
	string status[jml_res] = {
		"",
		"S01 - Penduduk / Pasien Biasa",
		"S02 - Orang Dalam Resiko",
		"S03 - Orang Tanpa Gejala",
		"S04.1 - Orang Dalam Pengawasan dengan kondisi Kriteria 1",
		"S04.2 - Orang Dalam Pengawasan dengan kondisi Kriteria 2",
		"S04.3 - Orang Dalam Pengawasan dengan kondisi Kriteria 3",
		"S05.1 - Pasien Dalam Pengawasan dengan kondisi Kriteria 1",
		"S05.2 - Pasien Dalam Pengawasan dengan kondisi Kriteria 2",
		"S05.3 - Pasien Dalam Pengawasan dengan kondisi Kriteria 3",
		"S06.1 - POSITIF COVID-19 kondisi Kriteria 1",
		"S06.2 - POSITIF COVID-19 kondisi Kriteria 2",
		"S06.3 - POSITIF COVID-19 kondisi Kriteria 3"
	};
	
	//init cf rule
		//status S02 - ODR
		double cf_s021[jml_ciri] = {0, 0.5, 0.5, 0, 0, 0, 0, 0, 0, 0};
		
		//status S03 - OTG
		double cf_s031[jml_ciri] = {0, 0.4, 0.4, 0.7, 0, 0, 0, 0, 0, 0};
		
		//status S04 - ODP
		double cf_s041[jml_ciri] = {0, 0.4, 0.4, 0, 0.7, 0, 0, 0.5, 0, 0};
		double cf_s042[jml_ciri] = {0, 0.4, 0.4, 0, 0, 0.7, 0, 0.5, 0, 0};
		double cf_s043[jml_ciri] = {0, 0, 0, 0.6, 0, 0.4, 0, 0, 0, 0};
		
		//status S05 - PDP
		double cf_s051[jml_ciri] = {0, 0.4, 0.4, 0, 0.5, 0.5, 0.7, 0.5, 0, 0};
		double cf_s052[jml_ciri] = {0, 0, 0, 0.6, 0.3, 0, 0.6, 0, 0, 0};
		double cf_s053[jml_ciri] = {0, 0, 0, 0, 0, 0, 0.6, 0.3, 0.6, 0};
		
		//status S06 - Positif
		double cf_s061[jml_ciri] = {0, 0.3, 0.3, 0, 0.5, 0.5, 0.7, 0.4, 0, 0.8};
		double cf_s062[jml_ciri] = {0, 0, 0, 0.5, 0.2, 0, 0.5, 0, 0, 0.8};
		double cf_s063[jml_ciri] = {0, 0, 0, 0, 0, 0, 0.5, 0.2, 0.5, 0.8};
	
	//------------------program start------------------//
	
	//init title
	cout << "\t\t\t SISTEM PAKAR" << endl;
	cout << " Penentuan Status Penduduk (Pasien) pada Masa Pandemi COVID-19" << endl;
	cout << "\t\t dengan Rule Based Reasoning" << endl;
	cout << " -------------------------------------------------------------" << endl;
	
	//init option
	cout << " Jawab semua pertanyaan berikut sesuai dengan tingkat\n keyakinan pada diri anda!" << endl;
	cout << " 0 = Tidak yakin" << endl;
	cout << " 1 = Tidak tahu" << endl;
	cout << " 2 = Sedikit yakin" << endl;
	cout << " 3 = Cukup yakin" << endl;
	cout << " 4 = Yakin" << endl;
	cout << " 5 = Sangat yakin" << endl;
	cout << " -------------------------------------------------------------" << endl;
	
	//init questionaire
	for(i=1; i<jml_ciri; i++){
		
		//last quest
		if(i == 9){
			cout << "\n " <<  i << ") " << ciris[0] << endl;
			cout << " Jawaban (y/n) : "; cin >> xc;
			
			//if true
			if(xc == 'y'){
				cout << "\n 10) " << ciris[i] << endl;
				cout << " Jawaban (0-5) : "; cin >> xi;  
				
				//wrong input beltline
				if((xi < 0) || (xi > 5)){
					do{
						cout << " Masukan tidak sesuai! Harap ulangi!" << endl;
						cout << " Jawaban (0-5) : "; cin >> xi;  
					} while (xi < 0 || xi > 5);
				}
				ans[i] = xi * 0.2; //cf user input
			} else if(xc == 'n'){
				ans[i] = 0; //cf user input
				
			//wrong input beltline
			} else {
				do{
					cout << " Masukan tidak sesuai! Harap ulangi!" << endl;
					cout << " Jawaban (y/n) : "; cin >> xc;  
				} while ((xc != 'y') || (xc != 'n'));
			}
		} 
		
		//normal quest
		else {
			cout << "\n " <<  i << ") " << ciris[i] << endl;
			cout << " Jawaban (0-5) : "; cin >> xi;  
			
			//wrong input beltline
			if((xi < 0) || (xi > 5)){
				do{
					cout << " Masukan tidak sesuai! Harap ulangi!" << endl;
					cout << " Jawaban (0-5) : "; cin >> xi;  
				} while (xi < 0 || xi > 5);
			}
			ans[i] = xi * 0.2; //cf user input
		}
		
		cek_s01 += ans[i];
		
	}
	
	//cek status S01 - Biasa
	res[1] = 100 - ((cek_s01 / 9) * 100);
	
	//cek status another
	res[2] = calc(ans, cf_s021);
	res[3] = calc(ans, cf_s031);
	res[4] = calc(ans, cf_s041);
	res[5] = calc(ans, cf_s042);
	res[6] = calc(ans, cf_s043);
	res[7] = calc(ans, cf_s051);
	res[8] = calc(ans, cf_s052);
	res[9] = calc(ans, cf_s053);
	res[10] = calc(ans, cf_s061);
	res[11] = calc(ans, cf_s062);
	res[12] = calc(ans, cf_s063);
	
	//show hasil
	cout << " -------------------------------------------------------------" << endl;
	cout << "\n Berdasarkan kondisi anda, didapat hasil seperti berikut :" << endl;
	//for loop print result
	for (i=1; i<jml_res; i++){
		//printf("Anda %.2f% berstatus %s\n",res[i],status[i]);
		cout << "Anda " << res[i] << "% " << "berstatus " << status[i] << endl;	
	}
	cout << "x untuk exit()";
	cin >> xi;
	return 0;
}
