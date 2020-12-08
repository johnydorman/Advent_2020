using System;
using System.IO;
using System.Linq;
using System.Collections;
using System.Collections.Generic;
 
namespace Day7
{
    public class Program
    {
		static Dictionary<string, Bag> bags;
		static HashSet<Bag> containsGold;

        static void Main(string[] args)
        {
			bags = new Dictionary<string, Bag>();
			
			string line;
			System.IO.StreamReader file = new System.IO.StreamReader(@"input.txt");  
			while((line = file.ReadLine()) != null)  
			{
				line = line.Replace("bags", "bag").Replace("contain ","").Replace(".", "").Replace(",","");

				string[] sss = line.Split(new String[]{"bag"}, StringSplitOptions.RemoveEmptyEntries);
				Bag bag = GetBag(sss[0].Trim());
				for(int i = 1; i < sss.Length; i++){
					string amount = sss[i].Substring(1,1);
					
					if(amount != "n"){
						int iAmount = Int32.Parse(amount);
						string colour = sss[i].Substring(3, sss[i].Length-3).Trim();
						Bag containedBag = GetBag(colour);
						bag.addBag(containedBag, iAmount);
					}
				}
			}

			int counter = 0;
			containsGold = new HashSet<Bag>();
			foreach(Bag bag in bags.Values){
				counter += checkBag(bag, 0);
			}
			Console.WriteLine("Total bags containing gold: " + (counter-1));
			
			counter = CountBags(bags["shiny gold"]);
			Console.WriteLine("Total bags in gold: " + counter);
        }
		
		public static int CountBags(Bag currentBag){
			int inBag = currentBag.GetContained().Values.Sum();
			
			foreach(var bagPair in currentBag.GetContained()){		
				inBag += CountBags(bagPair.Key) * bagPair.Value;
			}
			return inBag;
		}
		
		public static Bag GetBag(String colour){
			Bag bag;
			if(bags.ContainsKey(colour)){
				bag = bags[colour];
			} else {
				bag = new Bag(colour);
				bags.Add(colour, bag);
			}
			return bag;
		}
		
		public static int checkBag(Bag currentBag, int found){
			if(currentBag.getColour() == "shiny gold"){
				return 1;
			} else {
				foreach(Bag newBag in currentBag.getBags()){
					found = checkBag(newBag, found);
					
					if(found == 1 ) break;
				}
			}
			return found;
		}
    }
 
    public class Bag
    {
		private string colour;
		private Dictionary<Bag, int> containedBags;
		
		public Bag(string colour){
			this.colour = colour;
			this.containedBags = new Dictionary<Bag, int>();
		}
		
		public string getColour(){
			return colour;
		}
		
		public void addBag(Bag bag, int amount){
			containedBags.Add(bag, amount);
		}
		
		public List<Bag> getBags(){
			return containedBags.Keys.ToList();
		}
		
		public Dictionary<Bag, int> GetContained(){
			return containedBags;
		}
    }
}