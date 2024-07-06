# [Silver V] New Time - 26876 

[문제 링크](https://www.acmicpc.net/problem/26876) 

### 성능 요약

메모리: 2024 KB, 시간: 0 ms

### 분류

사칙연산, 너비 우선 탐색, 그래프 이론, 그래프 탐색, 그리디 알고리즘, 수학

### 제출 일자

2024년 7월 6일 14:24:30

### 문제 설명

<p>Nikolay has a digital clock that displays time in 24-hour format, showing two integers: hours (from <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>00</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$00$</span></mjx-container> to <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>23</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$23$</span></mjx-container>) and minutes (from <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>00</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$00$</span></mjx-container> to <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>59</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$59$</span></mjx-container>). For example, the clock can show <code>00:00</code>, <code>18:42</code>, or <code>23:59</code>.</p>

<p>The clock has two buttons that can be used for manual adjustment:</p>

<ul>
	<li>Button A sets the clock forward by <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container> minute. For example, <code>05:33</code> becomes <code>05:34</code>, <code>16:59</code> becomes <code>17:00</code>, and <code>23:59</code> becomes <code>00:00</code>.</li>
	<li>Button B sets the clock forward by <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$1$</span></mjx-container> hour. For example, <code>01:42</code> becomes <code>02:42</code>, and <code>23:14</code> becomes <code>00:14</code>.</li>
</ul>

<p>Nikolay has noticed that the time on his clock does not look right. He wants to adjust the clock to the correct time by pressing the buttons as few times as possible.</p>

<p>Find the smallest number of button presses needed to adjust the clock.</p>

### 입력 

 <p>The first line contains the time shown on the clock in the <code>hh:mm</code> format (<mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-texatom space="4" texclass="ORD"><mjx-mi class="mjx-ty"><mjx-c class="mjx-c1D691 TEX-T"></mjx-c><mjx-c class="mjx-c1D691 TEX-T"></mjx-c></mjx-mi></mjx-texatom><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c32"></mjx-c><mjx-c class="mjx-c33"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>00</mn><mo>≤</mo><mrow data-mjx-texclass="ORD"><mi mathvariant="monospace">hh</mi></mrow><mo>≤</mo><mn>23</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$00 \le \mathtt{hh} \le 23$</span></mjx-container>; <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mn class="mjx-n"><mjx-c class="mjx-c30"></mjx-c><mjx-c class="mjx-c30"></mjx-c></mjx-mn><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-texatom space="4" texclass="ORD"><mjx-mi class="mjx-ty"><mjx-c class="mjx-c1D696 TEX-T"></mjx-c><mjx-c class="mjx-c1D696 TEX-T"></mjx-c></mjx-mi></mjx-texatom><mjx-mo class="mjx-n" space="4"><mjx-c class="mjx-c2264"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="4"><mjx-c class="mjx-c35"></mjx-c><mjx-c class="mjx-c39"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mn>00</mn><mo>≤</mo><mrow data-mjx-texclass="ORD"><mi mathvariant="monospace">mm</mi></mrow><mo>≤</mo><mn>59</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$00 \le \mathtt{mm} \le 59$</span></mjx-container>).</p>

<p>The second line contains the correct time in the same format.</p>

### 출력 

 <p>Print a single integer --- the smallest number of button presses Nikolay needs to adjust the time on his clock.</p>

