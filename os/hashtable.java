import java.util.*;

class MyStructure {
    List<Integer> arr = new ArrayList<>();
    Map<Integer, Integer> map = new HashMap<>();

    public void insert(int x)
    {
        if (!map.containsKey(x)) {
            int index = arr.size();
            arr.add(x);
            map.put(x, index);
        }
    }

    public void remove(int x)
    {
        if (map.containsKey(x)) {
            int index = map.get(x);
            map.remove(x);
            if (index != arr.size() - 1) {
                int last = arr.size() - 1;
                Collections.swap(arr, index, last);
                if (last != index) {
                    map.put(arr.get(index), index);
                }
            }
            arr.remove(arr.size() - 1);
        }
    }

    public int search(int x)
    {
        return map.getOrDefault(x, -1);
    }

    public int getRandom()
    {
        Random rand = new Random();
        int randomIndex = rand.nextInt(arr.size());
        return arr.get(randomIndex);
    }
}

public class HashTableExample {
    public static void main(String[] args)
    {
        MyStructure ds = new MyStructure();
        ds.insert(10);
        ds.insert(20);
        ds.insert(30);
        ds.insert(40);
        System.out.println(ds.search(30));
        ds.remove(40);
        ds.insert(50);
        System.out.println(ds.search(50));
        System.out.println(ds.getRandom());
    }
}
