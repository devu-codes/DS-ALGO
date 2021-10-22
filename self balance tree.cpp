
// ============================= Self Balancing BST =========================

// Idea: Keep the height as O(LogN)
// 
 // -- AVL Tree (Strict in term of height)
 // -- Red-Black Tree (loose in term of height, requires less structuring)


//  ================================ AVL Tree =========================
//  It is a BST (for every node, left subtree is smaller and right greater).
//  It is balanced( For every node, difference between left and right height does not exceed one).

// Balance Factor = |Lh-Rh|
// Balance Factor <= 1

// search Operation -- same as BST 

// Insert Operation 
// Algorithm 
/*	- Perform Normal BST insert
	- Traverse all ancestor of the newly inserted node from the node to root 
	
	- If find unbalanced node, check for any of the below cases
	   - Left Left  -- SR (single Rotation)
	   - Right Right -- SR 
	   - Left Right  --DR (Double Rotation)
	   - Right Left -- DR 

	Height of AVL tree 
	h < clog(n+2) + b
	where c = 1.4405
	b = -1.327


	================================== Red Black Tree =========================
	
	Every Node is either Red or Black 
	Root is always black
	No two consecutive Reds
	Number of black nodes from every node to all of its descandent node should be same 

	if search operation is more use AVL Tree 
	but if mix like insertion, deletion etc .. use R-B Tree


	Applications 
	To maintain sorted stream of data (or sorted set of data)
	To implement double ended Priortiy quueue
	To solve problems like- 
		Count smaller/greater in a stream 
		Floor/ ceiling/Greater/smaller in a stream.
*/
