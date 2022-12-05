/**
 * Author: e-maxx
 * Date: 2022-06-06
 * License: Unknown
 * Source: cp-algorithms
 * Description: Returns the smallest $g$ s.t. for any $a$ the equation $g^x = a
 * \pmod n$ has a solution. Time: $O(Ans \cdot \log \phi(n) \cdot \log p)$
 */
#pragma once

int generator(int p) {
  vector<int> fact;
  int phi = p - 1, n = phi; // insert phi() computation for non-primes
  for (int i = 2; i * i <= n; ++i)
    if (n % i == 0) {
      fact.push_back(i);
      while (n % i == 0)
        n /= i;
    }
  if (n > 1)
    fact.push_back(n);

  for (int res = 2; res <= p; ++res) {
    bool ok = true;
    for (size_t i = 0; i < fact.size() && ok; ++i)
      ok &= powmod(res, phi / fact[i], p) != 1;
    if (ok)
      return res;
  }
  return -1;
}