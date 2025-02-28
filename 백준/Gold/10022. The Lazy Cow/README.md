# [Gold IV] The Lazy Cow - 10022 

[문제 링크](https://www.acmicpc.net/problem/10022) 

### 성능 요약

메모리: 3896 KB, 시간: 648 ms

### 분류

누적 합

### 제출 일자

2025년 3월 1일 00:36:19

### 문제 설명

<p>It's a hot summer day, and Bessie the cow is feeling quite lazy. She wants to locate herself at a position in her field so that she can reach as much delicious grass as possible within only a short distance.</p>

<p>The field Bessie inhabits is described by an N by N grid of square cells (1 <= N <= 400). The cell in row r and column c (1 <= r,c <= N) contains G(r,c) units of grass (0 <= G(r,c) <= 1000). From her initial square in the grid, Bessie is only willing to take up to K steps (0 <= K <= 2*N). Each step she takes moves her to a cell that is directly north, south, east, or west of her current location.</p>

<p>For example, suppose the grid is as follows, where (B) describes Bessie's initial position (here, in row 3, column 3):</p>

<pre>50    5     25*   6     17    
14    3*    2*    7*    21    
99*   10*   1*(B) 2*    80*    
8     7*    5*    23*   11   
10    0     78*   1     9        
</pre>

<p>If K=2, then Bessie can only reach the locations marked with *s.</p>

<p>Please help Bessie determine the maximum amount of grass she can reach, if she chooses the best possible initial location in the grid.</p>

### 입력 

 <ul>
	<li>Line 1: The integers N and K.</li>
	<li>Lines 2..1+N: Line r+1 contains N integers describing row r of the grid.</li>
</ul>

### 출력 

 <ul>
	<li>Line 1: The maximum amount of grass Bessie can reach, if she chooses the best possible initial location (the location from which she can reach the most grass).</li>
</ul>

