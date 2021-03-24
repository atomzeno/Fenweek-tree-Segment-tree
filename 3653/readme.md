# 3653
    
백준 3653 영화수집 문제를 각각 Fenwick tree, top-down Segment tree로 구현한 코드들입니다.
    
https://www.acmicpc.net/problem/3653
    
아이디어는 만일 제가 x번째 영화를 볼 때 그 영화 위에 있었던 DVD의 개수를 세고 싶다면, 
    
DVD j의 위치 x를 찾은 다음 쌓아놓은 콜렉션이 무너지지 않게 조심스럽게 DVD j를 빼는 것은 segment tree든 fenwick tree든 update로,
    
영화를 다 본 이후에는 가장 위에 놓는 것을 현재 가장 앞에 위치하는 DVD의 index를 y라고 주었을 때, 
    
y-1 의 위치에 1을 더해주고 DVD j의 위치를 y-1로 갱신해 주면 됩니다.
    
즉, 미리 앞에 m개의 공간을 비워두는 것이 핵심이라고 할 수 있습니다.
