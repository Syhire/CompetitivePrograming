// Javascript program to find Maximum sum
// subarray of size between L and R.

// function to find Maximum sum subarray
// of size between L and R
function max_sum_subarray(arr, L, R) {
  let n = arr.length;
  let pre = new Array(n);

  // calculating prefix sum
  pre[0] = arr[0];
  for (let i = 1; i < n; i++) {
    pre[i] = pre[i - 1] + arr[i];
  }
  let s1 = [];

  console.log(pre.join(", "));

  // maintain 0 for initial
  // values of i upto R
  // Once i = R, then
  // we need to erase that 0 from
  // our multiset as our first
  // index of subarray
  // cannot be 0 anymore.
  s1.push(0);
  let ans = Number.MIN_VALUE;

  ans = Math.max(ans, pre[L - 1]);

  // we maintain flag to
  // counter if that initial
  // 0 was erased from set or not.
  let flag = 0;

  for (let i = L; i < n; i++) {
    // console.log("index: " + i);
    // console.log(s1);
    // console.log(ans);

    // erase 0 from multiset once i=b
    if (i - R >= 0) {
      if (flag == 0) {
        let it = s1.indexOf(0);
        s1.splice(it, 1);
        flag = 1;
      }
    }

    // insert pre[i-L]
    if (i - L >= 0) s1.push(pre[i - L]);

    // find minimum value in multiset.
    ans = Math.max(ans, pre[i] - s1[0]);

    // erase pre[i-R]
    if (i - R >= 0) {
      let it = s1.indexOf(pre[i - R]);
      s1.splice(it, 1);
    }
  }

  return ans;
}

// Driver code
let L, R;
L = 1;
R = 3;
let arr = "-1 -1 2 2 -1".split(" ").map((c) => parseInt(c));

let max = max_sum_subarray(arr, L, L);
for (let i = L + 1; i <= R; i++)
  max = Math.max(max, max_sum_subarray(arr, L, i));

console.log(max);

// This code is contributed by avanitrachhadiya2155
