# [Gold III] Cent Savings - 10520 

[문제 링크](https://www.acmicpc.net/problem/10520) 

### 성능 요약

메모리: 2192 KB, 시간: 0 ms

### 분류

다이나믹 프로그래밍, 누적 합

### 제출 일자

2025년 3월 17일 16:36:41

### 문제 설명

<p>To host a regional contest like NWERC a lot of preparation is necessary: organizing rooms and computers, making a good problem set, inviting contestants, designing T-shirts, booking hotel rooms and so on. I am responsible for going shopping in the supermarket.</p>

<p>When I get to the cash register, I put all my n items on the conveyor belt and wait until all the other customers in the queue in front of me are served. While waiting, I realize that this supermarket recently started to round the total price of a purchase to the nearest multiple of 10 cents (with 5 cents being rounded upwards). For example, 94 cents are rounded to 90 cents, while 95 are rounded to 100.</p>

<p>It is possible to divide my purchase into groups and to pay for the parts separately. I managed to find d dividers to divide my purchase in up to d + 1 groups. I wonder where to place the dividers to minimize the total cost of my purchase. As I am running out of time, I do not want to rearrange items on the belt.</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>one line with two integers n (1 ≤ n ≤ 2 000) and d (1 ≤ d ≤ 20), the number of items and the number of available dividers;</li>
	<li>one line with n integers p<sub>1</sub>, . . . p<sub>n</sub> (1 ≤ p<sub>i</sub> ≤ 10 000 for 1 ≤ i ≤ n), the prices of the items in cents. The prices are given in the same order as the items appear on the belt.</li>
</ul>

### 출력 

 <p>Output the minimum amount of money needed to buy all the items, using up to d dividers.</p>

