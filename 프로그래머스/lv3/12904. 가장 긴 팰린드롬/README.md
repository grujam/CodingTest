# [level 3] 가장 긴 팰린드롬 - 12904 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/12904) 

### 성능 요약

메모리: 3.8 MB, 시간: 0.01 ms

### 구분

코딩테스트 연습 > 연습문제

### 채점결과

Empty

### 문제 설명

<p>앞뒤를 뒤집어도 똑같은 문자열을 팰린드롬(palindrome)이라고 합니다.<br>
문자열 s가 주어질 때, s의 부분문자열(Substring)중 가장 긴 팰린드롬의 길이를 return 하는 solution 함수를 완성해 주세요.</p>

<p>예를들면, 문자열 s가 "abcdcba"이면 7을 return하고 "abacde"이면 3을 return합니다.</p>

<h5>제한사항</h5>

<ul>
<li>문자열 s의 길이 : 2,500 이하의 자연수</li>
<li>문자열 s는 알파벳 소문자로만 구성</li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>s</th>
<th>answer</th>
</tr>
</thead>
        <tbody><tr>
<td>"abcdcba"</td>
<td>7</td>
</tr>
<tr>
<td>"abacde"</td>
<td>3</td>
</tr>
</tbody>
      </table>
<h5>입출력 예 설명</h5>

<p>입출력 예 #1<br>
4번째자리 'd'를 기준으로 문자열 s 전체가 팰린드롬이 되므로 7을 return합니다.</p>

<p>입출력 예 #2<br>
2번째자리 'b'를 기준으로 "aba"가 팰린드롬이 되므로 3을 return합니다.</p>

### 문제 유형
구현

### 풀이 과정
1. 문자열이 가지는 최대 길이의 팰린드롬을 확인하기 위해선 문자열의 길이 부터 2까지 팰린드롬이 존재하는지 문자열을 탐색해보아야 한다. (2까지 없다면 팰린드롬이 없으므로 1을 출력한다)
2. 크기가 큰 순으로 탐색하면 팰린드롬을 찾았을 때 탐색을 중지해도 됨으로 수행 시간을 아낄 수 있어 최대 크기부터 탐색을 시작한다.
3. 팰린드롬의 최대 크기는 문자열의 길이와 같고, 해당 길이부터 팰린드롬의 길이를 1씩 줄여가며 문자열에서 탐색한다.
4. 팰린드롬을 발견하면 해당 길이를 출력하고 리턴한다.

> 출처: 프로그래머스 코딩 테스트 연습, https://programmers.co.kr/learn/challenges
