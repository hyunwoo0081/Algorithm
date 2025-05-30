# [Gold V] 주작 주 주작 - 12792 

[문제 링크](https://www.acmicpc.net/problem/12792) 

### 성능 요약

메모리: 2020 KB, 시간: 104 ms

### 분류

수학, 정수론

### 제출 일자

2025년 4월 22일 20:59:00

### 문제 설명

<p>곧 다가올 학교 축제를 위해, 쿠사과는 참가비를 내고 여러 사람이 동시에 즐길 수 있는 게임을 만들었다. 이 게임의 알파이자 오메가는 추첨기이다. 이 추첨기는 1번부터 <em>N</em>번까지 둥글게 구멍이 위 아래로 하나씩 나 있고, 추첨기 윗편 구멍에 구슬을 넣으면 안에서 정해진 통로에 따라 복잡하게 움직이다가 아래 구멍 중 하나로 떨어지게 된다.</p>

<p>게임은 간단하다. <em>N</em>명이 동시에 모여 추첨기에서 1부터 <em>N</em>이 적힌 자리에 각각 한 명씩 선 뒤, 쿠사과가 1번 사람부터 <em>N</em>번 사람까지 차례로 돌아가면서 구슬을 하나씩 넣고, 어느 위치에 떨어지는지 본다. 만약 어떤 사람이 자신의 위치에서 넣은 구슬이 그대로 자신이 선 위치의 아래 구멍으로 나오게 되면 아무 일도 일어나지 않지만, 다른 자리에 떨어지면 그 사람은 경품을 얻게 된다. 단 모든 사람이 경품을 받는 경우, 즉 모든 사람이 자신이 선 위치와 다른 곳으로 구슬이 떨어지면 이 판은 잭팟이 되어 모두가 경품을 받지 못한다.</p>

<p>추첨기의 내부 동작에 대해 전혀 알 수 없는 사람들이 생각하기에는 그냥 웬만하면 경품을 얻는 꿀같은 게임이라고 생각하겠지만, 쿠사과의 생각은 조금 달랐다. 언듯 보기에는 구슬이 랜덤하게 떨어져 내려오는 것 같았지만 실제로는 사전에 정해진 결과대로 내려오기 때문이었다.</p>

<p>또한 추첨기를 처음 한 개 만드는 건 매우 어려웠지만 복제하는 것은 매우 간단했기 때문에, 추첨기에 똑같은 추첨기를 다시 연결하는 식으로 하면 겉에서 보기에는 하나의 추첨기이고 또 더 화려하게 움직이지만 내부적으로는 조작된 추첨기를 얻을 수 있다.</p>

<p>예를 들어 1 → 2, 2 → 1, 3 → 4, 4 → 3으로 구성된 추첨기가 있다면, 이건 이미 쿠사과가 무조건 이득을 보는 좋은 기계이다. 이 기계를 두 개 연결하게 되면 1 → 1, 2 → 2, 3 → 3, 4 → 4가 되어 아무런 일도 일어나지 않지만, 다시 한 개 더 연결하게 되면 처음처럼 쿠사과가 무조건 이득을 보는 좋은 기계가 된다.</p>

<p>이렇게 게임을 진행하면, 1번 사람부터 점점 다른 위치로 나와서 모두가 신나하다가, 점점 모두가 다른 위치로 나오는 것에 경악하게 될 것이다. 그리고 N번 사람의 구슬이 마지막 추첨기 밖으로 나오는 순간, 쿠사과는 "아이쿠 그런데 그것이 실제로 일어났습니다" 라고 말하며 즐거워할 생각에 가득차 있다.</p>

<p>쿠사과는 가급적이면 2개 이상의 추첨기를 서로 연결해 게임의 박진감을 불러일으키고자 한다. 추첨기가 주어질 때, 쿠사과가 이득을 보는 결과를 얻으려면 몇 개의 추첨기를 연결해야 할까?</p>

### 입력 

 <p>첫 줄에는 정수 <em>N</em> (1 ≤ <em>N</em> ≤ 1000000) 이 주어진다.  다음 줄에는 <em>N</em>개의 정수 <em>J<sub>i</sub></em>가 공백으로 구분되어 주어지며, 각 정수는 1에서 <em>N</em> 사이이며 끝을 포함한다. 이는 <em>i</em>번 자리에 선 사람이 얻게 되는 결과 정수를 뜻한다.</p>

### 출력 

 <p>추첨기를 몇 개 연속으로 연결하면 쿠사과가 이득을 보는 결과를 얻을 수 있는지 출력한다. 이 값은 2 이상 2 × 10<sup>9</sup> 이하여야 하지만, 조작된 결과를 얻을 수만 있다면 어떤 값이든 상관없다. 만약 주어진 범위 안에서 조작할 방법이 없다면 -1을 출력하라.</p>

