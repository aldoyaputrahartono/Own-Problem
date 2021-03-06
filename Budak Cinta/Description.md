<strong>Perbedaan versi easy dan hard hanyalah di batasannya</strong>

<p>Eyou dan Ilov adalah sepasang kekasih yang terpisah oleh jarak. Mereka berdua tinggal di kota yang berbeda. Tetapi mereka masih tetap berada di satu negara yaitu Enpisiesia. Di dalam Enpisiesia terdapat N buah kota yang dihubungkan oleh M buah jalan dua arah. Kota-kota tersebut dinomori dari 1 sampai N. Dijamin pasti ada cara untuk pergi dari satu kota ke kota lainnya menggunakan satu atau lebih ruas jalan.</p>

<p>Enpisiesia terbagi dalam beberapa provinsi yang berbeda. Dua buah kota U dan V berada di dalam provinsi yang sama jika dan hanya jika terdapat lebih dari 1 cara untuk pergi dari U ke V ataupun sebaliknya.</p>

<p>Negara Enpisiesia terkenal dengan teknologinya yang sangat maju. Salah satu teknologi kebanggaan bangsa Enpisinesia adalah &ldquo;Teleporter&rdquo;. Teleporter ini terdapat&nbsp; di semua kota di Enpisinesia. Dengan teleporter ini,seseorang dapat berpindahan dari satu kota ke kota lainnya dalam waktu sekejap. Tetapi,seseorang hanya dapat memakai teleporter untuk berpindah ke kota yang berada di dalam provinsi yang sama.&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;</p>

<p>Selanjutnya,anda diharuskan menjawab Q buah pertanyaan. Untuk setiap pertanyaan ke-i,anda diharuskan mencari total panjang jalan terpendek yang harus dilalui Eyou untuk sampai ke rumah Ilov jika keduanya masing-masing tinggal di kota X<sub>i</sub>&nbsp;dan Y<sub>i</sub></p>

<p><strong>Format Input</strong></p>

<p>Baris pertama terdiri dari 2 buah bilangan N dan M. Banyaknya kota serta jalan pada negara Enpisinesia</p>

<p>M baris selanjutnya terdiri dari 3 buah bilangan A<sub>i</sub>,B<sub>i</sub> dan W<sub>i</sub>. Yang berarti bahwa terdapat jalan yang menghubungkan kota A<sub>i</sub> dan B<sub>i</sub> sepanjang W<sub>i</sub>.</p>

<p>Baris selanjutnya terdiri dari 1 buah bilangan Q,yang melambangkan banyaknya query.</p>

<p>Q baris selanjutnya berisi 2 buah bilangan X<sub>i</sub>&nbsp;dan Y<sub>i</sub>&nbsp;seperti yang telah dijelaskan di deskrpisi soal.</p>

<p><strong>Format Output</strong></p>

<p>Q baris berisi sebuah bilangan yang merupakan jawaban dari masing-masing pertanyaan.</p>

<p><strong>Sample Input</strong></p>

<pre>
10 10
1 2 7
2 4 3
4 5 2
4 6 2
6 7 3
5 7 4
1 3 5
2 3 4
3 10 6
8 9 1
5 8 3
3
1 10
2 4
4 7
</pre>

<p><strong>Sample Output</strong></p>

<pre>
6
3
0
</pre>

<p><strong>Penjelasan</strong></p>

<p>Untuk query pertama, urutan perjalanan Ilov adalah</p>

<ul>
	<li>Dari Kota 1 ke Kota 3 menggunakan transporter</li>
	<li>Dari Kota 3 ke Kota 10 menggunakan jalan biasa.</li>
</ul>

<p>Total jalan yang dilewati Ilov adalah 0 + 6 = 6.</p>

<p>Untuk query kedua,Ilov dapat langsung menggunakan jalan biasa yang menghubungkan kota 2 dan 4</p>

<p>Untuk query ketiga,Ilov dapat pergi ke kota 5 menggunakan transporter lalu kembali menggunakan transporter untuk ke kota 7. Dengan begitu ia tidak perlu menggunakan jalan biasa sama sekali.</p>

<p><strong>Constraint</strong></p>

<ul>
	<li>2 &le; N &le; 10^5</li>
	<li>N &ndash; 1&le; M &le; min(n*(n-1),10^5)</li>
	<li>1 &le; Q &le; 10^5</li>
	<li>1 &le; W<sub>i</sub> &le; 10^9</li>
</ul>

<p><strong>Subtask 1 (8 Poin)</strong></p>

<p>2 &le; N &le; 1000</p>

<p>M = N &ndash; 1</p>

<p>Wi = Wi -1 untuk 1&le; i &le; M</p>

<p>1 &le; Q &le; 1000</p>

<p><strong>Subtask 2 (12 Poin)</strong></p>

<p>2 &le; N &le; 1000</p>

<p>M = N &ndash; 1</p>

<p>1 &le; Q &le; 1000</p>

<p><strong>Subtask 3 (10 Poin)</strong></p>

<p>2 &le; N &le; 1000</p>

<p>M = N &ndash; 1</p>

<p>1 &le; Q &le; 10^5</p>

<p><strong>Subtask 4 (22 Poin)</strong></p>

<p>2 &le; N &le; 10^5</p>

<p>M = N &ndash; 1</p>

<p>1 &le; Q &le; 10^5</p>

<p><strong>Subtask 5 (20 Poin)</strong></p>

<p>2 &le; N &le; 1000</p>

<p>1 &le; Q &le; 1000</p>

<p><strong>Subtask 6 (28 Poin)</strong></p>

<p>Tidak ada constraint tambahan.</p>
