# [Silver IV] 포스터 만들기 - 29693 

[문제 링크](https://www.acmicpc.net/problem/29693) 

### 성능 요약

메모리: 2124 KB, 시간: 0 ms

### 분류

해 구성하기

### 제출 일자

2024년 12월 16일 12:12:32

### 문제 설명

<p>대한민국을 지키는 가장 높은 힘! 대한민국 공군의 마크는 현재 다음과 같다.</p>

<p style="text-align: center;"><img alt="" src="" style="height: 501px; width: 600px;"></p>

<p>이 사진을 본 운영진은 자신만의 마크를 보라매컵 포스터에 포함하기로 하였다. 공군 마크를 분석한 결과, 다음과 같은 디자인을 협의할 수 있었다.</p>

<ol>
	<li>마크는 세로 $Y$칸, 가로 $X$칸의 크기이며, 좌우 대칭이어야 한다.</li>
	<li>각 칸은 흰색, 노란색, 파란색 중 하나로 색칠해야 하며, 특히 테두리는 파란색으로 칠해야 한다.</li>
	<li>어떤 색의 문양이란, 해당 색으로 색칠된 인접한 칸들의 묶음이다. 두 칸이 변을 공유하는 경우에 두 칸은 인접한다고 정의한다.</li>
	<li>마크 안엔 정확히 2개의 흰색 문양, 1개의 노란색 문양, 그리고 1개의 파란색 문양이 있어야 한다.</li>
	<li>두 흰색 문양은 중앙을 기준으로 서로 좌우 대칭 관계여야 한다.</li>
	<li>모든 흰색 문양은 노란색 문양과 한 칸 이상 변을 공유해야 한다.</li>
</ol>

<p>올바른 마크의 예시는 다음과 같다.</p>

<p style="text-align: center;"><img alt="" src="" style="height: 380px; width: 600px;"></p>

<p>올바르지 않은 마크의 예시와 관련 규칙은 다음과 같다.</p>

<p style="text-align: center;"><img alt="" src="" style="height: 411px; width: 600px;"></p>

<p>그런데 인쇄를 맡기기 직전에서야 인쇄용지의 일부가 이미 파란색으로 색칠되어 있음을 알게 되었다! 어쩔 수 없이 운영진은 인쇄용지의 상태에 맞춰서, 이미 색칠된 부분을 파란색으로 유지하면서 위의 조건을 여전히 만족하는 새로운 마크를 만들고자 한다.</p>

<p>용지의 크기 및 상태가 주어졌을 때, 새로운 마크를 만들 수 있는지 확인해 보자.</p>

### 입력 

 <p>첫 번째 줄에 세로 길이 $Y$와 가로 길이 $X$가 공백으로 구분되어 정수로 주어진다.</p>

<p>이후 $Y$줄에 걸쳐 인쇄용지의 상태가 주어진다.</p>

<p>각 줄은 $X$글자의 <span style="color:#e74c3c;"><code>B</code></span> 또는 <span style="color:#e74c3c;"><code>X</code></span>가 주어지며, <span style="color:#e74c3c;"><code>B</code></span>로 색칠된 칸은 결과물에서도 파란색으로 색칠되어야 한다.</p>

<p>단, 마크의 테두리는 언제나 <span style="color:#e74c3c;"><code>B</code></span>로 주어진다. 이는 위의 2번 규칙을 반영한 내용이다.</p>

### 출력 

 <p>첫 번째 줄에 모든 규칙을 만족하는 마크가 있다면 <span style="color:#e74c3c;"><code>YES</code></span>, 없다면 <span style="color:#e74c3c;"><code>NO</code></span>을 출력한다.</p>

<p>이후 <span style="color:#e74c3c;"><code>YES</code></span>를 출력했다면 $Y$줄에 걸쳐 가능한 마크 중 하나를 출력한다.</p>

<p>흰색으로 칠한 칸은 <span style="color:#e74c3c;"><code>W</code></span>, 노란색으로 칠한 칸은 <span style="color:#e74c3c;"><code>Y</code></span>, 파란색으로 칠한 칸은 <span style="color:#e74c3c;"><code>B</code></span>로 출력하라.</p>

