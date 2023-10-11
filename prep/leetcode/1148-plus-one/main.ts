function plusOne(digits: number[]): number[] {
    let d = digits.map(i => String(i));
    let x = BigInt(d.join(''));
    ++x;
    return x.toString().split('').map(i => parseInt(i))
};