import org.apache.commons.io.IOUtils
import java.net.URL
import java.nio.charset.Charset

val bankText =sc.textFile("file:/home/qm/Downloads/bank.csv")
case class Bank(age:Integer, job:String, marital:String, education:String, balance : Integer)
val bank = bankText.map(s=>s.split(";")).filter(s=>s(0)!="\"age\"").map(
s=>Bank(s(0).toInt,
s(1).replaceAll("\"", ""),
s(2).replaceAll("\"", ""),
s(3).replaceAll("\"", ""),
s(5).replaceAll("\"", "").toInt)
).toDF()
bank.registerTempTable("bank")

%sql
select martial, balance from bank where balance <1000
select job, balance from bank where balance < 1000
select education,balance from bank sort by balance
select age, balance from bank sort by balance

