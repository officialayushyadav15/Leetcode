class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        exp = expression

        def funct(exp, l, r):
            A = set()
            i = l

            while i < r:

                if exp[i] == "{":
                    c = 1
                    j = i + 1

                    while c != 0:
                        if exp[j] == "{":
                            c += 1
                        elif exp[j] == "}":
                            c -= 1
                        j += 1

                    q = funct(exp, i + 1, j - 1)

                    if not A:
                        A = q
                    else:
                        temp = set()

                        for t in A:
                            for y in q:
                                temp.add(t + y)

                        A = temp

                    i = j

                elif exp[i] == ",":
                    right = funct(exp, i + 1, r)
                    A = A | right
                    break

                else:
                    if not A:
                        A.add(exp[i])
                    else:
                        temp = set()

                        for t in A:
                            temp.add(t + exp[i])

                        A = temp

                    i += 1

            return A

        return sorted(funct(exp, 0, len(exp)))