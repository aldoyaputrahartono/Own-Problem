<p>Eyou adalah seorang Waba (pegawai baru) di suatu perusahaan yang dipimpin oleh Ilov. Sesuai tradisi perusahaan setiap tahunnya, para Waba-Waba akan diberikan beberapa penugasan agar mereka dapat diangkat menjadi Warga(pegawai keluarga). Pegawai-pegawai yang berstatus Warga memiliki beberapa keuntungan dibanding Waba. Salah satunya mendapatkan jaket perusahaan yang berwarna biru tua.</p>

<p>Terdapat N pegawai di perusahaaan ini(termasuk Eyou dan Ilov) yang dinomori dari 1 sampai N. Masing-masing pegawai kecuali Ilov memiliki tepat 1 orang atasan langsung. Jika C merupakan atasan langsung dari B,dan B merupakan atasan langsung dari A,maka C merupakan atasan dari A,tetapi bukan atasan langsung.</p>

<p>Level dari seorang pegawai adalah jumlah atasan yang dia miliki.Semakin tinggi jabatan seorang pegawai,semakin rendah juga levelnya. Tentunya,para Waba merupakan pegawai-pegawai dengan jabatan paling rendah.</p>

<p>Salah satu syarat untuk seorang Waba untuk meng-<em>upgrade</em> statusnya menjadi seorang Warga adalah mengenal dengan baik struktur pegawai di perusahaannya. Untuk menguji seberapa jauh seorang Waba mengenal rekan-rekan sejawatnya, Ilov akan memberikan sebuah tes yang disebut &ldquo;Tes Kenal Sejawat&rdquo;.</p>

<p>Dalam tes ini, Ilov akan memberikan suatu array A berukuran N yang merupakan permutasi dari bilangan 1-N, lalu dia akan memberikan Q buah pertanyaan. Pada masing &ndash; masing pertanyaan, Ilov akan memberikan 2 bilangan L dan R, para Waba yang dites diharuskan memilih satu orang sebagai pemimpin jika pegawai-pegawai&nbsp;yang berada di indeks ke-L sampai indeks ke-R diberi suatu proyek untuk dikerjakan bersama. Orang tersebut tidak harus merupakan salah satu pegawai-pegawai yang berada pada indeks ke-L sampai ke-R tadi tetapi pemimpin tersebut harus memiliki jabatan serendah mungkin. Perlu di perhatikan bahwa setiap pegawai hanya mau dipimpin oleh dirinya sendiri ataupun atasannya.</p>

<p>Eyou sangat ingin mendapatkan jaket perusahaannya, tetapi ia kesulitan untuk menjawab tes yang diberikan oleh Ilov. Maka dari itu, ia meminta kamu sebagai programmer handal untuk membantunya melewati tes ini</p>

<p><strong>Format Masukan</strong></p>

<p>Baris pertama terdapat sebuah bilangan T, yang merupakan banyaknya Testcase.</p>

<p>Untuk setiap Testcase, terdiri dari beberapa baris</p>

<p>Baris pertama,berisi 2 bilangan N dan Q. Yang merupakan banyaknya pegawai dan banyak pertanyaan yang akan diberikan.</p>

<p>Baris berikutnya berisi N bilangan B<sub>i</sub>&nbsp;yang menyatakan atasan langsung untuk pegawai ke-i. Jika B<sub>i</sub>&nbsp;bernilai -1,maka itu berarti pegawai tersebut tidak memiliki atasan langsung</p>

<p>Baris berikutnya berisi N bilangan A<sub>i</sub>&nbsp;yang merupakan permutasi yang diberikan oleh Ilov.</p>

<p>Q baris berikutnya berisi 2 bilangan L<sub>i</sub>&nbsp;dan R<sub>i</sub>&nbsp;yang merupakan pertanyaan yang diberikan oleh Ilov</p>

<p><strong>Format Keluaran</strong></p>

<p>Untuk setiap testcase,keluarkan Q baris yang berisi 1 buah bilangan yang merupakan jawaban dari pertanyaan-pertanyaan yang diberikan.</p>

<p><strong>Contoh Masukan</strong></p>

<pre>
1
6 2
3 3 -1 1 1 1
1 2 3 4 5 6
1 3
4 6
</pre>

<p><strong>Contoh Keluaran</strong></p>

<pre>
3
1
</pre>

<p><strong>Penjelasan</strong></p>

<p>Berikut merupakan struktur kepegawaian di perusahaan tersebut.</p>

<p style="text-align: center;"><img alt="" src="http://junior.npc.portal-schematics2019.com:9924/problems/3/statements/media/TKS_Explanation.PNG" /></p>

<p>Untuk query ke-2,perhatikan bahwa 1 dan 3 merupakan atasan dari 4,5 dan 6. Tetapi 1 memiliki jabatan yang lebih rendah.</p>

<p><strong>Batasan</strong></p>

<p>Untuk semua subsoal,berlaku :</p>

<p>1 &le;&nbsp;&nbsp;T&nbsp;&nbsp;&le; 10<br />
1 &le; N,Q&nbsp;&le; 10<sup>5</sup><br />
1&nbsp;&le; B<sub>i</sub>&nbsp;&le; N atau B<sub>i</sub>&nbsp;= -1<br />
1&nbsp;&le; A<sub>i</sub>&nbsp;&le; N, A<sub>i</sub>&nbsp;- 1&nbsp;&nbsp;&nbsp;&ne; A<sub>i</sub>&nbsp;untuk 1 &lt; i&nbsp;&le; N<br />
1&nbsp;&le; L&nbsp;&le; R&nbsp;&le; N</p>

<p><strong>Subsoal&nbsp;1 (5 poin)</strong></p>

<p>B<sub>1</sub>&nbsp;= -1</p>

<p>B<sub>i</sub>&nbsp;= i - 1 untuk 2&nbsp;&le; i&nbsp;&le; N<br />
1&nbsp;&le; N&nbsp;&le; 1000</p>

<p>1&nbsp;&le; Q&nbsp;&le; 1000<br />
<strong>Subsoal 2 (8 poin)</strong></p>

<p>1&nbsp;&le; N&nbsp;&le; 100</p>

<p>1&nbsp;&le; Q&nbsp;&le; 100</p>

<p>R<sub>i</sub>&nbsp;- L<sub>i</sub>&nbsp;&le;&nbsp;1</p>

<p><strong>Subsoal 3 (10 poin)</strong></p>

<p>1&nbsp;&le; N&nbsp;&le; 100</p>

<p>1&nbsp;&le; Q&nbsp;&le; 100</p>

<p><strong>Subsoal 4 (15 poin)</strong></p>

<p>1&nbsp;&le; N&nbsp;&le; 1000</p>

<p>1&nbsp;&le; Q&nbsp;&le; 1000</p>

<p><strong>Subsoal&nbsp;5 (27 poin)</strong></p>

<p>1&nbsp;&le; N&nbsp;&le; 1000</p>

<p>1&nbsp;&le; Q&nbsp;&le; 10<sup>5</sup></p>

<p><strong>Subsoal 6 (35 poin)</strong></p>

<p>Tidak ada constraint tambahan</p>

<p><!--![endif]----><!--![endif]----><!--![endif]----><!--![endif]----><!--![endif]----><!--![endif]----></p>
