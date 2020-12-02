
public class Policy {
	
	private char character;
	private int lower;
	private int upper;
	
	public Policy(String policyInfo) {
		String[] splt = policyInfo.split(" ");
		this.character = splt[1].charAt(0);
		
		String[] counts = splt[0].split("-");
		this.lower = Integer.parseInt(counts[0]);
		this.upper = Integer.parseInt(counts[1]);
	}
	
	public char getExpectedCharacter() {
		return character;
	}
	
	public int getLower() {
		return lower;
	}
	
	public int getUpper() {
		return upper;
	}
	
	public boolean isCountAcceptable(int count) {
		if(count <= upper && count >= lower) {
			return true;
		}
		
		return false;
	}
}
