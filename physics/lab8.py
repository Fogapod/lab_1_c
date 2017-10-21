#coding:utf8


PI  = 3.14
dPI = 0.005
dm  = dr = 0.5
dT0 = dT = 0.0005

RADIUS_INTERVAL = 2  # сантиметры

TABLE_2_MASS = 12.5  # граммы
TABLE_3_MASS = 25    # граммы


def get_T0_and_T():
    T0 = float(input('Введите среднее значение T0 из таблицы 1 (в сантиметрах): ').replace(',', '.'))
    T  = float(input('Введите среднее значение T  из таблицы 1 (в сантиметрах): ').replace(',', '.'))

    return T0, T


def calculate_D(T0, T):
    m = 50  # граммы
    r = 20  # свнтиметры

    formula = (
        '4 * (PI ** 2) * ((2 * m * (r ** 2)) '
        '/ ((T ** 2) - (T0 ** 2)))'
        )
    print(
        (
            '\nИспользую формулу D = %s\n\n'
            '\tPI = %g\n'
            '\tm  = %d\n'
            '\tr  = %d\n'
        ) % (formula, PI, m, r)
    )

    return eval(formula)


def calculate_ED(T0, T):
    r   = 20  # сантиметры
    m   = 50  # граммы

    formula = '2 * (dPI / PI) + dm/m + 2 * (dr / r) + 2 * (dT0 / T0) + 2 * (dT / T)'
    
    print(
        (
            '\nИспользую формулу E(D) = %s\n\n'
            '\tPI = %g  dPI = %g\n'
            '\tm  = %d   dm = %g\n'
            '\tr  = %d   dr = %g\n'
            '\tdT0 = dT = %g\n'
        ) % (formula, PI, dPI, m, dm, r, dr, dT)
    )


    return eval(formula)


def calculate_J0(D, T0):
    formula = 'D * ((T0 ** 2) / (4 * (PI ** 2)))'

    print(
        (
            '\nИспользую формулу J0 = %s\n\n'
            '\tPI = %g\n'
        ) % (formula, PI)
        
    )

    return eval(formula)


def calculate_EJ0(dD, D, T0):
    formula = '2 * (dPI / PI) + dD / D + 2 * (dT0 / T0)'

    print(
        (
            '\nИспользую формулу E(J0) = %s\n\n'
            '\tPI = %g  dPI = %g\n'
        ) % (formula, PI, dPI)
    )

    return eval(formula)


def calculate_J(D, m):
    T = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]

    for i in range(10):
        T[i] = float(input('Значение T в строке %2d (в секундах): ' % (i + 1)).replace(',', '.'))

    formula = 'D * ((T ** 2) / (4 * (PI ** 2)))'
    print(
        (
            '\nИспользую формулу J = %s\n\n'
            '\tPI = %g\n'
        ) % (formula, PI)
    )
    
    formula = formula.replace('T', 'T[i]')

    for i in range(10):
        yield eval(formula)


if __name__ == '__main__':
    T0, T = get_T0_and_T()

    D = calculate_D(T0, T)
    print('D: %f' % D)

    ED = calculate_ED(T0, T)
    print('E(D): %f = dD / D' % ED)

    dD = ED * D

    print('dD: %f (E(D) * D)\n' % dD)
    print('Результат: D = (%f ± %f) (округлите самостоятельно!)' % (D, dD))

    
    J0 = calculate_J0(D, T0)
    print('J0: %f' %J0)

    EJ0 = calculate_EJ0(dD, D, T0)
    print('E(J0): %f = dJ0 / J0' % EJ0)

    dJ0 = J0 * EJ0

    print('dJ0: %f (E(J0) * J0)\n' % dJ0)
    print('Результат: J0 = (%f ± %f) (округлите самостоятельно!)' % (J0, dJ0))

    # ТАБЛИЦА 2

    print('\nВведите данные таблицы 2:')
    for i, J in enumerate(calculate_J(D, TABLE_2_MASS)):
        print('[%2d] J = %f' % (i + 1, J))

    # ТАБЛИЦА 3

    print('\nВведите данные таблицы 3:')
    for i, J in enumerate(calculate_J(D, TABLE_3_MASS)):
        print('[%2d] J = %f' % (i + 1, J))

    print('\nВы превосходны!')
