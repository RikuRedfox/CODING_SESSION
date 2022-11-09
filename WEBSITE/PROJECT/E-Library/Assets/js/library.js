$(document).ready( function () {

	$('.display').DataTable({
		autoWidth: true
	});

	$("a[data-toggle='list']").on("shown.bs.tab", function (e) { $($.fn.dataTable.tables(true)).DataTable() .responsive.recalc() .columns.adjust(); });
} );