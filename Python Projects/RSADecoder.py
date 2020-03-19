def egcd(a, b):
    """
    Euclid's Extended GCD algorithm.
    https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm
    """

    if a == 0:
        return b, 0, 1
    else:
        g, y, x = egcd(b % a, a)

    return g, x - (b // a) * y, y



def modinv(a, m):
    """
    Modular inverse using the e-GCD algorithm.
    https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Computing_multiplicative_inverses_$
    """

    g, x, y = egcd(a, m)
    
    if g != 1:
        raise Exception('Modular inverse does not exist')
    else:
        return x % m


p = 3725388540036591041643678991347701532937995068972047889459827083352416094739748803290082375874981227998371945676111
q = 6769093863386297883488638026341328618874310635474126545969024032791150452455022144768609227282398126000693285501811
e = 65537
n = p * q
phi = (p-1) * (q-1)
d = modinv(e, phi)

c = 6622134070245691926996690308636014521286935741634261181087265897986185018162369958862196354607409823650060083771844108483125982217500810571329331739793531038267151817809752836841785323152293094359142542286156837710367592316963064
print("hello")
print(pow(c,d,n))

x = 10365949062659381670709757727749292003316647434177486566829869211503534952303894644921906986089140732545322157880701

def int_to_bytes(x: int) -> bytes:
    print(x.to_bytes((x.bit_length() + 7) // 8, 'big').decode('ascii'))
int_to_bytes(x)
