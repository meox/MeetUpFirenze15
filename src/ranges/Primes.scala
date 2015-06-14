


object Primes {
  
  def is_prime(n: Int): Boolean = {
    var e = 3
    while (e * e <= n) {
      if (n % e == 0) { return false }
      e += 2
    }

    true
  }

  def gen_primes(m: Int) = 
    2 #:: Stream.from(3, 2) filter { e => is_prime(e) } take m
    
  def primes(m : Int) = {
      gen_primes(m) foreach println      
  }
  
  def main(args: Array[String]) {
    if (args.size == 0)
      primes(10)
    else
      primes(args(0).toInt)
  }

}
