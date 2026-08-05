<h2><a href="https://www.geeksforgeeks.org/problems/find-whether-path-exist5238/1?page=1&difficulty%5B%5D=1&category%5B%5D=Graph&sortBy=submissions">Check for Path in a 2D Grid with Obstacles</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">Given a grid <strong>mat[][]</strong> of size<strong> n × n</strong> containing integers <strong>0</strong>, <strong>1</strong>, <strong>2</strong>, and <strong>3 </strong>having the following meanings</span></p>
<ul>
<li><span style="font-size: 14pt;">1 represents the source cell</span></li>
<li><span style="font-size: 14pt;">2 represents the destination cell</span></li>
<li><span style="font-size: 14pt;">3 represents a blank cell through which movement is allowed</span></li>
<li><span style="font-size: 14pt;">0 represents a wall that cannot be traversed</span></li>
</ul>
<p><span style="font-size: 14pt;">There is exactly one source and one destination in the grid.&nbsp;</span></p>
<ul>
<li><span style="font-size: 14pt;">Find whether a path exists from the source cell to the destination cell.&nbsp;</span></li>
<li><span style="font-size: 14pt;">Movement is allowed in four directions: up, down, left, and right.</span></li>
</ul>
<p><span style="font-size: 18px;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">mat[][] = {{0,3,1,0}, {3,0,3,3}, {2,3,0,3}, {0,3,3,3}}; 
</span><strong style="font-size: 18px;">Output: </strong><span style="font-size: 18px;">true
</span><strong style="font-size: 18px;">Explanation: </strong><span style="font-size: 18px;">A path exists from source 1 to destination 2 through valid cells 3.</span><strong style="font-size: 18px;"><br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/929461/Web/Other/blobid1_1780917809.png" width="338" height="155"></strong></span>
</pre>
<pre><span style="font-size: 18px;"><strong style="font-size: 18px;">Input: </strong><span style="font-size: 18px;">mat[][] = {{1,0,3}, {0,0,0}, {3,3,2}};
</span><strong style="font-size: 18px;">Output: </strong><span style="font-size: 18px;">false
</span><strong style="font-size: 18px;">Explanation: </strong><span style="font-size: 18px;">No path exists as the source 1 is blocked and cannot reach destination 2.</span><strong style="font-size: 18px;"><br></strong></span><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/929461/Web/Other/blobid2_1780918858.png" width="331" height="152"> </pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ n ≤ 500</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Morgan Stanley</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Samsung</code>&nbsp;<code>Adobe</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>DFS</code>&nbsp;<code>Matrix</code>&nbsp;<code>Graph</code>&nbsp;<code>BFS</code>&nbsp;