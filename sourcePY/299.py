    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        if secret is None:
            return ""
        m = [0]*256
        a, b = 0, 0
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                a += 1
            else:
                m[int(secret[i])] += 1
                m[int(guess[i])] -= 1
                if m[int(secret[i])] <= 0:
                    b += 1
                if m[int(guess[i])] >= 0:
                    b += 1
        return str(a)+'A'+str(b)+'B'