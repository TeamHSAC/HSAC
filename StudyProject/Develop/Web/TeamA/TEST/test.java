import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.StringTokenizer;

// BOJ #10167 금광 
class Point implements Comparable<Point>{
	int y, x, w;
	public Point(int y, int x, int w) {
		this.y = y;
		this.x = x;
		this.w = w;
	}
	@Override
	public int compareTo(Point o) {
		return this.y - o.y;
	}
}
class Node{
	int Rval, Lval, val, all;
	public Node(int Rval, int Lval, int val, int all) {
		this.Rval = Rval;
		this.Lval = Lval;
		this.val = val;
		this.all = all;
	}
}
public class Main {

	static Node[] tree;
	static int[] xarr;
	static long max = 0;
	static int size = 2, xcnt, ycnt;
	static final int MIN = (int)-1e9;
	
	static void construct() {
		for(int i = size / 2 - 1 ; i > 0 ; i --) {
			int Rv, Lv, v, a;
			Rv = Math.max(tree[i * 2 + 1].all + tree[i * 2].Rval, tree[i * 2 + 1].Rval);
			Lv = Math.max(tree[i * 2].all + tree[i * 2 + 1].Lval, tree[i * 2].Lval);
			v = Math.max(tree[i * 2].val, tree[i * 2 + 1].val);
			v = Math.max(tree[i * 2].Rval + tree[i * 2 + 1].Lval, v);
			a = tree[i * 2].all + tree[i * 2 + 1].all;
			tree[i] = new Node(Rv, Lv, v, a);
		}
	}
	
	static void update(int i, int N) {
		if(i < 0 || i >= N) return;
		i += size / 2;
		tree[i].Lval = 1 - tree[i].Lval;
		tree[i].Rval = 1 - tree[i].Rval;
		tree[i].all = 1 - tree[i].all;
		tree[i].val = 1 - tree[i].val;
		while(i > 1) {
			i /= 2;
			int Rv, Lv, v, a;
			Rv = Math.max(tree[i * 2 + 1].all + tree[i * 2].Rval, tree[i * 2 + 1].Rval);
			Lv = Math.max(tree[i * 2].all + tree[i * 2 + 1].Lval, tree[i * 2].Lval);
			v = Math.max(tree[i * 2].val, tree[i * 2 + 1].val);
			v = Math.max(tree[i * 2].Rval + tree[i * 2 + 1].Lval, v);
			a = tree[i * 2].all + tree[i * 2 + 1].all;
			tree[i].Lval = Lv;
			tree[i].Rval = Rv;
			tree[i].val = v;
			tree[i].all = a;
		}
	}
	
	static void clear() {
		tree = new Node[size];
		for(int i = 0 ; i < size / 2 ; i ++) {
			if(i < xcnt) {
				tree[size / 2 + i] = new Node(0, 0, 0, 0);
			}
			else tree[size / 2 + i] = new Node(MIN, MIN, MIN, 0);
		}
	}
	
	static int getMax() {
		int max = Integer.MIN_VALUE;
		max = Math.max(tree[1].Lval, tree[1].Rval);
		max = Math.max(tree[1].val, max);
		max = Math.max(tree[1].all, max);
		return max;
	}
	public static void main(String[] args) throws IOException {
		Main T = new Main();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		xarr = new int[N];
		
		ArrayList<Point> list = new ArrayList<Point>();
		for(int i = 0 ; i < N ; i ++) {
			st = new StringTokenizer(br.readLine());
			int xp = Integer.parseInt(st.nextToken());
			xarr[i] = xp;
			list.add(new Point(xp, Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken())));
		}
		Arrays.sort(xarr);
		int last = Integer.MIN_VALUE;
		HashMap<Integer, Integer> xidx = new HashMap<Integer, Integer>();
		xcnt = 0;
		for(int i = 0 ; i < xarr.length ; i ++) {
			if(xarr[i] != last) {
				xidx.put(xarr[i],  ++ xcnt);
			}
		}
		Collections.sort(list);
		last = Integer.MIN_VALUE;
		ycnt = 0;
		for(int i = 0 ; i < N ; i ++) {
			Point tmp = list.get(i);
			if(tmp.y == last) {
				tmp.y = ycnt;
			}
			else {
				last = tmp.y;
				tmp.y = ++ycnt;
				
			}
			tmp.x = xidx.get(tmp.x);
		}
		
		while(true) {
			if(size >= xcnt) {
				size *= 2;
				break;
			}
			size *= 2;
		}
		T.clear();
		T.construct();
		for(int i = 1 ; i <= ycnt ; i ++) {
			T.clear();
			T.construct();
			int lastY = Integer.MIN_VALUE;
			for(int j = 0 ; j < list.size() ; j ++) {
				Point tmp = list.get(j);
				if(tmp.y < i) continue;
				if(tmp.y == lastY) {
					T.update(tmp.x - 1, tmp.w);
				}
				else {
					Node t = tree[1];
					int tmpMax = Math.max(t.Lval, t.Rval);
					tmpMax = Math.max(t.val, tmpMax);
					tmpMax = Math.max(t.all, tmpMax);
					max = Math.max(tmpMax, max);
					lastY = tmp.y;
					j --;
				}
			}
		}
		System.out.println(max);
	}
}	
