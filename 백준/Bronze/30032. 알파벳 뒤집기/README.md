# [Bronze III] 알파벳 뒤집기 - 30032 

[문제 링크](https://www.acmicpc.net/problem/30032) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

구현

### 제출 일자

2025년 12월 27일 01:10:53

### 문제 설명

<p style="text-align:center;"><img alt="" src="" width="400px"></p>

<p>알파벳 소문자 <code>d</code>, <code>b</code>, <code>q</code>, <code>p</code>는 상하좌우로 뒤집으면 <code>d</code>, <code>b</code>, <code>q</code>, <code>p</code> 중 하나로 변하는 특별한 성질이 있다. 그 성질을 정리하면 다음과 같다.</p>

<ul>
	<li><code>d</code>를 상하로 뒤집으면 <code>q</code>로, 좌우로 뒤집으면 <code>b</code>로 변한다.</li>
	<li><code>b</code>를 상하로 뒤집으면 <code>p</code>로, 좌우로 뒤집으면 <code>d</code>로 변한다.</li>
	<li><code>q</code>를 상하로 뒤집으면 <code>d</code>로, 좌우로 뒤집으면 <code>p</code>로 변한다.</li>
	<li><code>p</code>를 상하로 뒤집으면 <code>b</code>로, 좌우로 뒤집으면 <code>q</code>로 변한다.</li>
</ul>

<p>$N$행 $N$열의 격자의 각 칸에 <code>d</code>, <code>b</code>, <code>q</code>, <code>p</code> 중 하나가 들어 있다. 이 격자에 들어 있는 각각의 알파벳을 주어진 방향으로 뒤집은 결과를 구해보자.</p>

### 입력 

 <p>첫째 줄에 정수 $N(1\le N\le 10)$과 각각의 알파벳을 뒤집는 방향을 의미하는 정수 $D(1\le D\le 2)$가 공백으로 구분되어 주어진다. $D=1$는 상하 방향, $D=2$는 좌우 방향을 의미한다.</p>

<p>둘째 줄부터 $N$개의 줄에 길이가 $N$인 문자열이 주어진다. $i$번째 줄의 $j$번째 문자는 격자의 $i$행 $j$열에 들어 있는 문자를 의미한다. 격자의 각 칸에는 알파벳 소문자 <code>d</code>, <code>b</code>, <code>q</code>, <code>p</code> 중 하나가 들어 있다.</p>

### 출력 

 <p>주어진 격자에 들어있는 각각의 알파벳을 주어진 방향으로 뒤집은 결과를 구해보자.</p>

