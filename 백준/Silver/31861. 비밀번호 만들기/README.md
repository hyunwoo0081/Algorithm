# [Silver I] 비밀번호 만들기 - 31861 

[문제 링크](https://www.acmicpc.net/problem/31861) 

### 성능 요약

메모리: 2020 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2025년 10월 16일 21:01:20

### 문제 설명

<p>혜민이는 자신만의 규칙으로 비밀번호를 만들어내고 싶다. <span style="color:#e74c3c;"><code>A</code></span>부터 <span style="color:#e74c3c;"><code>Z</code></span>까지 순서대로 $1$부터 $26$까지 번호를 지정했을 때, 알파벳 사이의 거리는 알파벳 번호의 차이이다. 혜민이는 $M$ 자리의 비밀번호를 만든다면 몇 개를 만들 수 있는지 알고 싶다. 비밀번호를 만드는 규칙은 다음과 같다.</p>

<ul>
	<li>$2$ 이상 $M$ 이하의 정수 $i$에 대해, $i - 1$번째 알파벳과 $i$번째 알파벳 사이의 거리가 $N$ 이상이 되도록 한다.</li>
	<li>알파벳은 대문자만 사용한다.</li>
	<li>알파벳은 중복으로 사용이 가능하다.</li>
</ul>

<p>예를 들어, $N=24$, $M=4$인 경우, 첫 번째 알파벳이 <span style="color:#e74c3c;"><code>A</code></span>이면 <span style="color:#e74c3c;"><code>AYAY</code>, <code>AYAZ</code>, <code>AZAY</code>, <code>AZAZ</code>, <code>AZBZ</code></span>를, <span style="color:#e74c3c;"><code>Z</code></span>이면 <span style="color:#e74c3c;"><code>ZAYA</code>, <code>ZAZA</code>, <code>ZAZB</code>, <code>ZBZA</code>, <code>ZBZB</code></span>를, <span style="color:#e74c3c;"><code>B</code></span>이면 <span style="color:#e74c3c;"><code>BZAY</code>, <code>BZAZ</code>, <code>BZBZ</code></span>를, <span style="color:#e74c3c;"><code>Y</code></span>이면 <span style="color:#e74c3c;"><code>YAYA</code>, <code>YAZA</code>, <code>YAZB</code></span>를 만들 수 있다. 따라서 $5+5+3+3$으로 총 $16$개의 비밀번호를 만들 수 있다.</p>

<p>만들 수 있는 비밀번호의 개수를 $1 \, 000 \, 000 \, 007 \left(=\ 10^9 + 7 \right)$로 나눈 나머지를 출력해 보자.</p>

### 입력 

 <p>첫째 줄에 정수 $N(0 \leq N \leq 25)$과 $M(2 \leq M \leq 1 \, 000)$이 공백으로 구분되어 주어진다.</p>

### 출력 

 <p>만들 수 있는 비밀번호의 개수를 $1 \, 000 \, 000 \, 007$로 나눈 나머지를 출력한다.</p>

