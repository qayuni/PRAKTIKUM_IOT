# POSTTEST 1

## Nama dan NIM Anggota Kelompok
1. Qurrata A'yuni (2309106001)
2. Nur Juzieatul Alifah (2309106040)
3. Tiara Kasma Wati Putri (2309106080)

## Judul Studi Kasus
Monitoring dan Kontrol Gas Berbasis IoT Menggunakan ESP32 dan Sensor MQ-2

## Deskripsi
Proyek ini merupakan sistem monitoring dan kontrol kadar gas berbasis Internet of Things (IoT) menggunakan ESP32 dan sensor gas MQ-2. Sensor MQ-2 digunakan untuk mendeteksi gas seperti LPG, asap, dan gas mudah terbakar lainnya di lingkungan.

Sistem ini dapat membaca nilai kadar gas dan memberikan indikator melalui tiga LED berdasarkan rentang nilai gas yang terdeteksi. Selain itu, sistem juga terhubung dengan platform IoT sehingga pengguna dapat memantau nilai gas secara real-time dan mengontrol LED secara manual melalui dashboard ketika tidak ada gas yang terdeteksi.

Adapun mekanisme sistem:
- Jika nilai gas 0–200, maka LED1 akan berkedip selama 3 detik
- Jika nilai gas 201–500, maka LED2 akan berkedip selama 5 detik
- Jika nilai gas >500, maka LED3 akan berkedip selama 7 detik
- Jika tidak ada gas terdeteksi, maka LED dapat dikontrol melalui platform IoT

## Pembagian Tugas
- Qurrata A'yuni : Membuat kode program dan error handling code
- Nur Juzieatul Alifah : Membuat rangkaian alat dan error handling rangkaian
- Tiara Kasma Wati Putri : Mengatur platform IoT (pembuatan device hingga dashboard)

## Komponen yang Digunakan
- ESP32
- Sensor Gas MQ-2
- LED (3 buah)
- Kabel jumper
- Breadboard
- Koneksi Wi-Fi

## Board Schematic

Sensor MQ-2:
- VCC → 5V 
- GND → GND
- AOUT → GPIO 34

LED:
- LED1 → GPIO 16 → GND
- LED2 → GPIO 17 → GND
- LED3 → GPIO 18 → GND
