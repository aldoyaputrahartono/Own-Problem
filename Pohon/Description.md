<h3>Deskripsi</h3>

<p style="text-align: justify;">Diberikan sebuah <em>rooted tree</em> yang terdiri dari <em>N</em> node dengan node 1 sebagai <em>root</em> dari tree tersebut. Di setiap node terdapat salah satu karakter dari &lsquo;a&rsquo; sampai &lsquo;z&rsquo;.</p>

<p>Diberikan <em>Q</em> buah query yang terdiri dari 2 tipe :</p>

<ul>
	<li style="text-align: justify;">Tipe pertama meng-<em>update</em> karakter-karakter yang berada pada <em>subtree </em>u menjadi 1 karakter setelahnya. Asumsikan karakter-karakter tersebut bersifat sirkular yang artinya setelah di<em>update</em> karakter &lsquo;z&rsquo; akan menjadi karakter &lsquo;a&rsquo;</li>
	<li style="text-align: justify;">Tipe kedua,diberikan sebuah string,tentukan apakah kita dapat membentuk string tersebut menggunakan karakter-karakter yang berada pada <em>subtree</em> node u.</li>
</ul>

<h3>Format Masukan</h3>

<p>Baris pertama berisi 2 buah bilangan <em>N</em> dan <em>Q</em>. Banyaknya node dan banyaknya query</p>

<p>Baris berikutnya berisi <em>N - 1</em> bilangan A<sub><span style="font-size:10.8333px">i</span></sub>&nbsp;dimana A<sub>i</sub>&nbsp;berarti parent dari node <em>i - 1</em> pada tree.</p>

<p>Baris berikutnya berisi <em>N</em> buah karakter B<sub>i</sub>&nbsp;dimana B<sub>i</sub>&nbsp;merupakan karakter yang ada pada node <em>i</em></p>

<p><em>Q</em> baris berikutnya berisi query-query dengan format:</p>

<ul>
	<li>&ldquo;1 u&rdquo; untuk query tipe pertama. Dengan u merupakan root dari subtree yang akan di<em>update</em></li>
	<li>&ldquo;2 u s&rdquo; untuk query tipe kedua. Dengan u merupakan root dari subtree serta s adalah string yang akan dibentuk</li>
</ul>

<h3>Format Keluaran</h3>

<p>Untuk setiap query tipe 2,keluarkan &ldquo;YA&rdquo; jika bisa membentuk string yang diberikan dan &ldquo;TIDAK&rdquo; jika tidak.</p>

<h3>Contoh Masukan</h3>

<pre>
12 5
1 1 1 2 2 2 3 8 8 6 6
a a k b c i c m a u n t
2 1 aku
2 2 cinta
2 1 kamu
1 1
2 1 kamu
</pre>

<h3>Contoh Keluaran</h3>

<pre>
YA
YA
YA
TIDAK
</pre>

<h3>Batasan</h3>

<ul>
	<li>Untuk semua subsoal berlaku</li>
	<li>1 &le; <em>N</em>,<em>Q</em> &le; 10<sup>5</sup></li>
	<li>1 &le; A<sub>i</sub>&nbsp;&le; N</li>
	<li>B<sub>i</sub>&nbsp;hanya terdiri dari karakter &lsquo;a&rsquo; &ndash; &lsquo;z&rsquo;</li>
	<li>|<em>s</em>| &le; <em>N</em></li>
	<li>1 &le; <em>u</em> &le; <em>N</em></li>
	<li>Total |<em>s</em>| tidak lebih dari 5*10<sup>5</sup></li>
</ul>

<h3>Subsoal</h3>

<h4>Subsoal 1 (10 Poin)</h4>

<ul>
	<li>1 &le; N,Q &le; 10<sup>3</sup></li>
	<li>A_i = i untuk 1 &le; i &le; N</li>
</ul>

<h4>Subsoal 2 (13&nbsp;Poin)</h4>

<ul>
	<li>A_i = i untuk 1 &le; i &le; N</li>
	<li>Tidak ada query tipe 1</li>
</ul>

<h4>Subsoal 3 (32&nbsp;Poin)</h4>

<ul>
	<li>A_i = i untuk 1 &le; i &le; N</li>
</ul>

<h4>Subsoal 4 (12&nbsp;Poin)</h4>

<ul>
	<li>1 &le; N,Q &le; 10<sup>3</sup></li>
</ul>

<h4>Subsoal 5 (15&nbsp;Poin)</h4>

<ul>
	<li>Tidak ada query tipe 1</li>
</ul>

<h4>Subsoal 6 (18 Poin)</h4>

<ul>
	<li>Tidak ada batasan tambahan.</li>
</ul>
